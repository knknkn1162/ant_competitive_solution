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
    COMMAND_UPDATE,
    COMMAND_GET_SUM
};

struct range {
    int start;
    int end;
};

struct pair {
    int64_t lazy;
    int64_t val;
};

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)
#define QUERY_MAX 100000

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

#define INIT_VAL (2e+9)

void unlazy(struct pair *seg, int node, struct range nr) {
    int64_t lazy = seg[node].lazy;
    if(lazy == INIT_VAL) return;
    seg[node].val = lazy; //update
    seg[node].lazy = INIT_VAL;
    if(nr.end - nr.start > 1) {
        seg[node*2].lazy = lazy/2;
        seg[node*2+1].lazy = lazy/2;
    }
    return;
}


void update_range(struct pair *seg, int x, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy = x * (nr.end - nr.start);
        unlazy(seg, node, nr);
        return;
    }
    struct range left = { nr.start, (nr.start + nr.end)/2 };
    struct range right = { (nr.start + nr.end)/2, nr.end };
    update_range(seg, x, r, node*2, left);
    update_range(seg, x, r, node*2+1, right);
    seg[node].val = seg[node*2].val + seg[node*2+1].val;
}

int64_t get_sum(struct pair *seg, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) {
        return seg[node].val;
    }
    struct range left = { nr.start, (nr.start + nr.end)/2 };
    struct range right = { (nr.start + nr.end)/2, nr.end };
    int64_t ans = 0;
    ans += get_sum(seg, r, node*2, left);
    ans += get_sum(seg, r, node*2+1, right);
    return ans;
}


#define ROOT_NODE 1
int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    int num2 = 1;
    static int64_t ans[QUERY_MAX];
    int aidx = 0;
    while(num > num2) num2 *= 2;
    static struct pair seg[NUM2_MAX*2];
    int i;
    for(i = ROOT_NODE; i < num2*2; i++) seg[i].lazy = INIT_VAL;

    struct range whole = {0, num2};
    for(i = 0; i < queries; i++) {
        int start, end;
        int type;
        get_int3(&type, &start, &end);
        struct range r = {start, end+1};
        switch(type) {
            case COMMAND_UPDATE:
                {
                    int x = get_int();
                    update_range(seg, x, r, ROOT_NODE, whole);
                }
                break;
            case COMMAND_GET_SUM:
                ans[aidx++] = get_sum(seg, r, ROOT_NODE, whole);
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
