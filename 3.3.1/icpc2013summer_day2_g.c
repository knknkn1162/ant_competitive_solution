#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

void swap(int64_t *a, int64_t *b) {
    int64_t tmp = *a;
    *a = *b;
    *b = tmp;
}


struct pair { int x; int y; };

struct pair gcdext(int a, int b) {
    if(a==0) return (struct pair){0, 1};
    struct pair p = gcdext(b%a, a);
    return (struct pair){p.y - (b/a)*p.x, p.x};
}

int64_t gcd(int64_t a, int64_t b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

#define DIVISOR 1000000007
// assume that a < b
int64_t lcm(int64_t a, int64_t b) {
    if(a > b) swap(&a, &b);
    int64_t g = gcd(a,b);
    int64_t res = g/DIVISOR;
    struct pair p = gcdext(g%DIVISOR, DIVISOR);
    res = (res + DIVISOR + p.x)%DIVISOR;
    int64_t ans = 1;
    ans = (ans * a * b)%DIVISOR;
    ans = (ans * res)%DIVISOR;
    return g ? ans : 1;
}

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)
#define PERM_MAX 40
#define ROOT_NODE 1

void init_seg_lcm(int64_t *seg, int num, char *arr, int size) {
    int i;
    for(i = ROOT_NODE; i < num*2; i++) seg[i] = 1;
    for(i = 1; i <= size; i++) {
        seg[i+num] = arr[i];
    }
    for(i = num-1; i >= ROOT_NODE; i--) {
        seg[i] = lcm(seg[i*2], seg[i*2+1]);
    }
    return;
}

void init_seg_sum(int64_t* seg, int num, int64_t *arr, int size) {
    int i;
    for(i = 1; i <= size; i++) {
        seg[i+num] = arr[i];
    }
    for(i = num-1; i >= ROOT_NODE; i--) {
        seg[i] = (seg[i*2] + seg[i*2+1])%DIVISOR;
    }
    return;
}

struct range {
    int start;
    int end;
};

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

int64_t get_lcm(int64_t *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 1;
    if(is_contain(nr, r)) return seg[node];
    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    int64_t res1 = get_lcm(seg, r, node*2, left);
    int64_t res2 = get_lcm(seg, r, node*2+1, right);
    return lcm(res1, res2);
}

int64_t get_sum(int64_t *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    return (get_sum(seg, r, node*2, left) + get_sum(seg, r, node*2+1, right))%DIVISOR;
}

#define QUERY_MAX 10000

int main(void) {
    int num, queries;
    get_int2(&num, &queries);

    static int arr[NUM_MAX+1];
    static int64_t ans[QUERY_MAX];
    int aidx = 0;
    int i, j;
    for(i = 1; i <= num; i++) arr[i] = i;
    static int mat[NUM_MAX+1];
    static int64_t sum[NUM_MAX+1];
    static char lcms[NUM_MAX+1];
    static int64_t sums[PERM_MAX+1][NUM_MAX+1];
    fget_array(&mat[1], num);
    int perms;
    for(perms = 1; perms <= PERM_MAX; perms++) {
        for(j = 1; j <= num; j++) {
            arr[j] = mat[arr[j]];
            if(!lcms[j]) sum[j] = (arr[j] + sum[j])%DIVISOR;
            if(arr[j] == j) {
                if(!lcms[j]) {
                    lcms[j] = perms;
                    sums[perms][j] = sum[j];
                }
            }
        }
    }

    int num2 = 1;
    while(num >= num2) num2 *= 2;
    static int64_t seg_lcm[NUM2_MAX*2];
    init_seg_lcm(seg_lcm, num2, lcms, num);

    static int64_t seg_sum[PERM_MAX+1][NUM2_MAX*2];
    static int64_t inv[PERM_MAX+1];
    int p;
    for(p = 1; p <= PERM_MAX; p++) {
        init_seg_sum(seg_sum[p], num2, sums[p], num);
        struct pair pa = gcdext(p, DIVISOR);
        inv[p] = (pa.x + DIVISOR)%DIVISOR;
    }

    struct range whole = {0, num2};
    for(i = 0; i < queries; i++) {
        int start, end;
        get_int2(&start, &end);
        int64_t res = 0;
        struct range r = {start, end+1};
        int64_t cnt = get_lcm(seg_lcm, r, ROOT_NODE, whole);
        for(p = 1; p <= PERM_MAX; p++) {
            int64_t sum = get_sum(seg_sum[p], r, ROOT_NODE, whole);
#ifdef DEBUG
            printf("%d: %lld/%lld\n", p, sum, cnt);
#endif
            // sum * cnt / p
            int64_t tmp = (cnt * inv[p])%DIVISOR;
            tmp = (tmp * sum)%DIVISOR;
            res = (res + tmp)%DIVISOR;
        }
        ans[aidx++] = res;
    }
    for(i = 0; i < aidx; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
