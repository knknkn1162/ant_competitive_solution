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

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)
#define QUERY_MAX 100000
#define ROOT_NODE 1

struct range {
    int start;
    int end;
};

enum command {
    COMMAND_INVERSE = 1,
    COMMAND_GET_COUNT = 2,
};

struct pair {
    int val;
    int lazy;
};

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

void unlazy(struct pair *seg, int node, struct range nr) {
    int lazy = seg[node].lazy;
    if(!lazy) return;
    // inverse or stay
    if(lazy%2) seg[node].val = (nr.end-nr.start) - seg[node].val;
    seg[node].lazy = 0;
    if(nr.end - nr.start > 1) {
        seg[node*2].lazy += lazy;
        seg[node*2+1].lazy += lazy;
    }
}


void inverse_range(struct pair *seg, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy++;
        unlazy(seg, node, nr);
        return;
    }
    struct range left = {nr.start, (nr.start + nr.end)/2};
    struct range right = {(nr.start + nr.end)/2, nr.end};
    inverse_range(seg, r, node*2, left);
    inverse_range(seg, r, node*2+1, right);
    seg[node].val = seg[node*2].val + seg[node*2+1].val;
    return;
}

int get_count(struct pair *seg, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) {
        return seg[node].val;
    }
    struct range left = {nr.start, (nr.start + nr.end)/2};
    struct range right = {(nr.start + nr.end)/2, nr.end};
    int m1 = get_count(seg, r, node*2, left);
    int m2 = get_count(seg, r, node*2+1, right);
    return m1 + m2;
}

int main(void) {
    int num, qs;
    get_int2(&num, &qs);

    int num2 = 1;
    while(num > num2) num2 *= 2;
    static struct pair seg[NUM2_MAX*2];
    int i;
    static int ans[QUERY_MAX];
    int aidx = 0;
    struct range whole = {0, num2};
    for(i = 0; i < qs; i++) {
        int type;
        struct range r;
        get_int3(&type, &r.start, &r.end);
        switch(type) {
            case COMMAND_INVERSE:
                inverse_range(seg, r, ROOT_NODE, whole);
                break;
            case COMMAND_GET_COUNT:
                ans[aidx++] = get_count(seg, r, ROOT_NODE, whole);
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
