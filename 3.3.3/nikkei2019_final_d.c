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

struct range {
    int start;
    int end;
};

struct pair {
    int64_t val;
    int64_t lazy;
    int64_t lazy_sum;
};

#define NUM_MAX ((int)(2e+5))
#define EVENT_MAX ((int)(2e+5))
#define NUM2_MAX (1<<18)
#define ROOT_NODE 1

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

#define INF (-1)
void unlazy(struct pair *seg, int node, struct range nr) {
    if(seg[node].lazy == INF) return;
    int64_t lazy = seg[node].lazy;
    seg[node].val = seg[node].lazy;
    seg[node].lazy = INF;
    if(nr.end - nr.start > 1) {
        seg[node*2].lazy = lazy/2;
        seg[node*2+1].lazy = lazy/2;
    }
    return;
}

int64_t get_sum(struct pair *seg, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) {
        return seg[node].val;
    }
    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    int64_t m1 = get_sum(seg, r, node*2, left);
    int64_t m2 = get_sum(seg, r, node*2+1, right);
    return m1 + m2;
}

void update_range(struct pair *seg, int64_t val, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy = val*(nr.end-nr.start); // update
        unlazy(seg, node, nr);
        return;
    }

    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    update_range(seg, val, r, node*2, left);
    update_range(seg, val, r, node*2+1, right);
    seg[node].val = seg[node*2].val + seg[node*2+1].val;
    return;
}

#define CHECKED 1

struct event {
    int time;
    struct range range;
};

int main(void) {
    int banboos, es;
    get_int2(&banboos, &es);
    int num2 = 1;
    while(banboos > num2) num2 *= 2;
    static struct event events[EVENT_MAX];
    int i;
    for(i = 0; i < es; i++) {
        int time, left, right;
        get_int3(&time, &left, &right);
        // 0-indexed, [left-1, right)
        events[i] = (struct event){time, {left-1, right}};
    }
    static struct pair seg[NUM2_MAX*2];
    for(i = ROOT_NODE; i < num2*2; i++) seg[i].lazy = INF;
    struct range whole = {0, num2};
    int64_t ans = 0;

    for(i = es-1; i >= 0; i--) {
        struct event e = events[i];
        int len = e.range.end - e.range.start;
        int cnt = len - get_sum(seg, e.range, ROOT_NODE, whole);
#ifdef DEBUG
        printf("%d*%d\n", cnt, e.time);
#endif
        ans += (int64_t)e.time * cnt;
        // Deforestation
        update_range(seg, CHECKED, e.range, ROOT_NODE, whole);
    }
    printf("%lld\n", ans);
    return 0;
}
