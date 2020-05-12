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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

#define QUERY_MAX 100000
#define NUM_MAX (1<<17)

enum {
    COMMAND_ADD,
    COMMAND_GET_SUM,
};

struct range {
    int start;
    int end;
};

void add(int *seg, int num, int idx, int x) {
    int node = num + idx;
    while(node) {
        seg[node] += x;
        node /= 2;
    }
    return;
}

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

int is_contain(struct range r, struct range in) {
    return r.end <= in.end && in.start <= r.start;
}

int64_t get_sum(int *seg, struct range target, int node, struct range this) {
#ifdef DEBUG
    printf("get_sum(seg, (%d,%d), %d, (%d,%d))\n", target.start, target.end, node, this.start, this.end);
#endif
    if(!is_overlap(target, this)) return 0;
    if(is_contain(this, target)) {
        return seg[node];
    }
    // if overlap
    struct range left = { this.start, (this.start+this.end)/2 };
    struct range right = { left.end+1, this.end };
    int64_t s1 = get_sum(seg, target, node*2, left);
    int64_t s2 = get_sum(seg, target, node*2+1, right);
    return s1 + s2;
}

#define ROOT_NODE 1

int main(void) {
    int _num, queries;
    get_int2(&_num, &queries);
    int num = 1;
    while(_num > num) num*=2;
    static int seg[NUM_MAX*2];
    static int64_t ans[QUERY_MAX];
    int aidx = 0;
    int i;
    struct range whole = {0, num-1};
    for(i = 0; i < queries; i++) {
        int type; int arg1, arg2;
        get_int3(&type, &arg1, &arg2);
        switch(type) {
            case COMMAND_ADD:
                {
                    int idx = arg1; int x = arg2;
                    // idx: 1-indexed -> 0-indexed
                    idx--;
                    add(seg, num, idx, x);
                }
                break;
            case COMMAND_GET_SUM:
                {
                    struct range r = {arg1-1, arg2-1};
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
