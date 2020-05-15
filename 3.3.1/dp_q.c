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
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

struct flower {
    int height;
    int point;
};

#define NUM_MAX 200000
// 262144
#define NUM2_MAX (1<<18)
#define ROOT_NODE 1

struct range {
    int start;
    int end;
};

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

int is_contain(struct range elem, struct range box) {
    return elem.start >= box.start && elem.end <= box.end;
}

int64_t get_max(int64_t* seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    struct range left = { nr.start, (nr.start + nr.end)/2 };
    struct range right = {left.end+1, nr.end};
    int64_t m1 = get_max(seg, r, node*2, left);
    int64_t m2 = get_max(seg, r, node*2+1, right);
    return max(m1, m2);
}

void update(int64_t *seg, int num, int idx, int64_t val) {
    int node = num + idx;
    seg[node] = val;
    while((node = node/2)) {
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }
#ifdef DEBUG
    int i;
    for(i = num; i < 2*num; i++) {
        printf(" %lld", seg[i]);
    }
    putchar('\n');
#endif
    return;
}

int main(void) {
    int num = get_int();
    static int heights[NUM_MAX+1];
    static int points[NUM_MAX+1];
    static int64_t seg[NUM2_MAX*2];

    
    int i;
    fget_array(heights, num);
    fget_array(points, num);
    int num2 = 1;

    // 1-indexed
    while(num >= num2) num2 *= 2;

    struct range whole = {0, num2-1};
    for(i = 1; i <= num; i++) {
        int cur = heights[i-1];
        int64_t point = points[i-1];
        struct range r = {0, cur-1};
        int64_t new = get_max(seg, r, ROOT_NODE, whole) + point;
#ifdef DEBUG
        printf("%d: %lld\n", i, new);
#endif
        if(new > seg[num2+cur]) {
            update(seg, num2, cur, new);
        }
    }

    printf("%lld\n", seg[ROOT_NODE]);

    return 0;
}
