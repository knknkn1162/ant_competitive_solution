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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

enum type {
    COMMAND_ADD,
    COMMAND_GET_SUM,
};

struct pair {
    int64_t sum;
    int64_t lazy_sum;
};

struct range {
    int start;
    int end;
};

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)

#define ROOT_NODE 1

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range elem, struct range box) {
    return elem.start >= box.start && elem.end <= box.end;
}

void unlazy(struct pair *seg, int node, struct range nr) {
    if(!seg[node].lazy_sum) return;
    int64_t lazy = seg[node].lazy_sum;
    seg[node].sum += lazy;
    seg[node].lazy_sum = 0;
    // if not simple
    if(nr.end - nr.start > 1) {
        seg[node*2].lazy_sum += lazy / 2;
        seg[node*2+1].lazy_sum += lazy / 2;
    }
}

void add_range(struct pair *seg, int64_t val, struct range r, int node, struct range nr) {

    // First of all, the lazy value should be woken
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy_sum += val * (nr.end-nr.start);
#ifdef DEBUG
        printf("add_range: %d.lazy_sum -> %d\n", node, val*(nr.end-nr.start));
#endif
        unlazy(seg, node, nr);
        return;
    }
    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    add_range(seg, val, r, node*2, left);
    add_range(seg, val, r, node*2+1, right);
    seg[node].sum = seg[node*2].sum + seg[node*2+1].sum;
}

int64_t get_sum(struct pair *seg, struct range r, int node, struct range nr) {

    // First of all, the lazy value should be woken
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node].sum;

    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    int64_t s1 = get_sum(seg, r, node*2, left);
    int64_t s2 = get_sum(seg, r, node*2+1, right);
    return s1 + s2;
}


int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    int i;
    static struct pair seg[NUM2_MAX*2];
    static int64_t ans[NUM_MAX];
    int aidx = 0;

    int num2 = 1;
    while(num > num2) num2 *= 2;

    struct range whole = {0, num2};
    for(i = 0; i < queries; i++) {
        int type = get_int();
        switch(type) {
            case COMMAND_ADD:
                {
                    int start, end, val;
                    get_int3(&start, &end, &val);
                    // 1-indexed -> 0-indexed
                    start--; end--;
                    struct range r = {start, end+1};
                    add_range(seg, val, r, ROOT_NODE, whole);
                }
                break;
            case COMMAND_GET_SUM:
                {
                    int start, end;
                    get_int2(&start, &end);
                    // 1-indexed -> 0-indexed
                    start--; end--;
                    struct range r = {start, end+1};
                    ans[aidx++] = get_sum(seg, r, ROOT_NODE, whole);
                }
                break;
            default:
                break;
        }
    }
    for(i = 0; i < aidx; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
