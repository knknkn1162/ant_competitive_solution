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

struct range {
    int start;
    int end;
};

#define NUM_MAX 100000
#define NUM2_MAX  (1<<17)
#define QUERY_MAX 100000

enum type {
    COMMAND_ADD,
    COMMAND_FIND,
};

struct pair {
    int lazy;
    int val;
};

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

#include <limits.h>
#define INF INT_MAX
void unlazy(struct pair *seg, int node, struct range nr) {
    int lazy = seg[node].lazy;
    seg[node].val += lazy;
    seg[node].lazy = 0;
    // propagate
    if(nr.end - nr.start > 1) {
        seg[node*2].lazy += lazy;
        seg[node*2+1].lazy += lazy;
    }
}

void add_range(struct pair *seg, int x, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy += x;
        unlazy(seg, node, nr);
        return;
    }
    struct range left = { nr.start, (nr.start + nr.end)/2};
    struct range right = { (nr.start + nr.end)/2, nr.end};
    add_range(seg, x, r, node*2, left);
    add_range(seg, x, r, node*2+1, right);
    seg[node].val = min(seg[node*2].val, seg[node*2+1].val);
}

int find_min(struct pair *seg, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return INF;
    if(is_contain(nr, r)) {
        return seg[node].val;
    }
    struct range left = { nr.start, (nr.start + nr.end)/2};
    struct range right = { (nr.start + nr.end)/2, nr.end};
    int m1 = find_min(seg, r, node*2, left);
    int m2 = find_min(seg, r, node*2+1, right);
    return min(m1, m2);
}

#define ROOT_NODE 1
int main(void) {
    int num, queries;
    static int ans[QUERY_MAX];
    int aidx = 0;
    get_int2(&num, &queries);
    int num2 = 1;
    while(num > num2) num2 *= 2;

    // the initial values are 0
    static struct pair seg[NUM2_MAX*2];
    int q, i;
    struct range whole = {0, num2};
    for(q = 0; q < queries; q++) {
        int start, end;
        int type;
        get_int3(&type, &start, &end);
        // 0-indexed
        struct range r = {start, end+1};
        switch(type) {
            case COMMAND_ADD:
                {
                    int x = get_int();
                    add_range(seg, x, r, ROOT_NODE, whole);
                }
                break;
            case COMMAND_FIND:
                ans[aidx++] = find_min(seg, r, ROOT_NODE, whole);
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
