#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)

// [start, end)
struct range {
    int start;
    int end;
};

#define ROOT_NODE 1

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

int64_t get_max(int64_t *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    struct range left = { nr.start, (nr.start + nr.end)/2 };
    struct range right = { (nr.start + nr.end)/2, nr.end };
    int64_t m1 = get_max(seg, r, node*2, left);
    int64_t m2 = get_max(seg, r, node*2+1, right);
    return max(m1, m2);
}

void update(int64_t *seg, int num, int64_t val, int idx) {
    int node = num + idx;
    seg[node] = val;
    while((node = node/2)) {
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }
    return;
}

int main(void) {
    int num = get_int();
    int num2 = 1;
    while(num > num2) num2 *= 2;
    static int64_t books[NUM_MAX];
    static int64_t weights[NUM_MAX];
    fget_array(weights, num);
    fget_array(books, num);
    int64_t sum = 0;
    int i;
    for(i = 0; i < num; i++) sum += weights[i];

    // 1-indexed -> 0-indexed
    for(i = 0; i < num; i++) books[i]--;
    static int64_t seg[NUM2_MAX*2];

    struct range whole = {0, num2};
    for(i = 0; i < num; i++) {
        int idx = books[i];
        struct range r = {0, idx};
        int64_t new = get_max(seg, r, ROOT_NODE, whole) + (int64_t)weights[idx];
        // books[i] is unique value
        update(seg, num2, new, books[idx]);
    }

    printf("%lld\n", (sum - seg[ROOT_NODE])*2);
    return 0;
}
