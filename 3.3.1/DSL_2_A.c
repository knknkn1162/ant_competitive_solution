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

enum type {
    COMMAND_UPDATE,
    COMMAND_FIND_MIN,
};

// 65536*2
#define NUM_MAX (1<<17)
#define QUERY_MAX 100000
#include <limits.h>
#define INF INT_MAX

void init_segtree(int *seg, int num) {
    int i;
    for(i = 0; i < num*2; i++) seg[i] = INF;
}

struct range {
    int start;
    int end;
};

int is_contain(struct range elem, struct range box) {
    return box.start <= elem.start && elem.end <= box.end;
}

int is_overlap(struct range r1, struct range r2) {
    return r1.start <= r2.end && r2.start <= r1.end;
}

int find_min(int *seg, struct range r, int node, struct range cur) {
#ifdef DEBUG
    printf("find_min: %d: %d-%d <= %d-%d\n", node, r.start, r.end, cur.start, cur.end);
#endif
    if(!is_overlap(cur, r)) return INF;
    if(is_contain(cur, r)) {
        return seg[node];
    } else {
        struct range left = {cur.start, (cur.start+cur.end)/2};
        struct range right = {(cur.start+cur.end)/2 + 1, cur.end};
        int v1 = find_min(seg, r, node*2, left);
        int v2 = find_min(seg, r, node*2+1, right);
        return min(v1, v2);
    }
}

void update(int *seg, int num, int idx, int x) {
    int node = num+idx;
#ifdef DEBUG
    printf("update(seg, %d, %d, %d) -> update node: %d\n", num, idx, x, node);
#endif
    seg[node] = x;
    while((node = node/2)) {
        int left = node*2;
        int right = node*2+1;
        seg[node] = min(seg[left], seg[right]);
    }
#ifdef DEBUG
    int i;
    for(i = num; i < 2*num; i++) {
        printf(" %d", seg[i] == INF ? -1 : seg[i]);
    }
    putchar('\n');
#endif
    return;
}

#define ROOT_NODE 1

int main(void) {
    int _num, queries;
    get_int2(&_num, &queries);
    int num = 1;
    while(_num > num) num*=2;
#ifdef DEBUG
    printf("num: %d\n", num);
#endif
    static int ans[QUERY_MAX];
    int aidx = 0;
    int i;
    struct range whole = {0, num-1};
    static int seg[NUM_MAX*2];
    init_segtree(seg, num);
    for(i = 0; i < queries; i++) {
        int type; int arg1, arg2;
        get_int3(&type, &arg1, &arg2);
        switch(type) {
            case COMMAND_UPDATE:
                {
                    int idx = arg1; int x = arg2;
                    update(seg, num, idx, x);
                }
                break;
            case COMMAND_FIND_MIN:
                {
                    struct range r = {arg1, arg2};
                    ans[aidx++] = find_min(seg, r, ROOT_NODE, whole);
                }
                break;
            default:
                break;
        }
    }

    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
