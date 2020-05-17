#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
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

#define NUM_2_MAX 317
#define NUM_MAX (NUM_2_MAX * NUM_2_MAX)
#define QUERIES_MAX 5000
struct range {
    int start;
    int end;
};

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

#define INF (1e+9)

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

int judge(int x, int key) { return x < key; }

int lower_bound(int *arr, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(judge(arr[mid], key)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int get_cnt(int *arr, int *sorted, int unit, int groups, int key, struct range r) {
    int g;
    int i;
    int ans = 0;
    for(g = 0; g < groups; g++) {
        struct range nr = {unit*g, unit*g+unit};
        if(!is_overlap(r, nr)) continue;
        if(is_contain(nr, r)) {
            int nidx = lower_bound(&sorted[nr.start], unit, key);
            ans += (nidx+1);
        } else {
            // ad-hoc
            for(i = nr.start; i < nr.end; i++) {
                if(r.start <= i && r.end > i) {
                    if(judge(arr[i], key)) ans++;
                }
            }
        }
    }
    return ans;
}

#define UNIT_MAX 2000

int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    int i;

    static int ans[QUERIES_MAX];
    int aidx = 0;
    static int arr[NUM_MAX];
    static int sorted[NUM_MAX];
    memset(arr, 0x7F, sizeof(int)*(NUM_MAX));
    fget_array(arr, num);
    memcpy(sorted, arr, sizeof(int)*(NUM_MAX));

    int unit = min(sqrt(num-0.5) + 1, UNIT_MAX);
    int groups = (num-1)/unit + 1;
    for(i = 0; i < groups; i++) {
        qsort(&sorted[unit*i], unit, sizeof(int), asc);
    }
#ifdef DEBUG
    putchar('\n');
    for(i = 0; i < num; i++) {
        printf(" %d", sorted[i]);
    }
    putchar('\n');
#endif

    for(i = 0; i < queries; i++) {
        int start, end, k;
        get_int3(&start, &end, &k);
        start--; end--;
        struct range r = {start, end+1};
        int low = -INF-1;
        int high = INF+1;
        // binary search
        while(low + 1 < high) {
            int mid = (low + high) / 2;
            int cnt = get_cnt(arr, sorted, unit, groups, mid, r);
#ifdef DEBUG
            printf("%d: %d([%d, %d]) -> %d\n", i, mid, low, high, cnt);
#endif
            if(cnt < k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        ans[aidx++] = low;
    }

    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
