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

struct range {
    int start;
    int end;
};

#define NUM_MAX 100000
#define TIME_MAX 100000
#define TIME2_MAX (1<<17)
#define ROOT_NODE 1

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
    seg[node].val += lazy;
    seg[node].lazy = 0;
    if(nr.end - nr.start > 1) {
        seg[node*2].lazy += lazy;
        seg[node*2+1].lazy += lazy;
    }
    return;
}

int get_cnt(struct pair *seg, int num) {
    struct range whole = {0, num};
    unlazy(seg, ROOT_NODE, whole);
    return seg[ROOT_NODE].val;
}

void add_range(struct pair *seg, int val, struct range r, int node, struct range nr) {
    unlazy(seg, node, nr);
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy += val;
        unlazy(seg, node, nr);
        return;
    }
    struct range left = { nr.start, (nr.start + nr.end)/2 };
    struct range right = { (nr.start + nr.end)/2, nr.end };
    add_range(seg, val, r, node*2, left);
    add_range(seg, val, r, node*2+1, right);
    seg[node].val = max(seg[node*2].val, seg[node*2+1].val);
}

int main(void) {
    int num = get_int();
    int i;
    static int cnt[TIME_MAX];
    static struct range ranges[NUM_MAX];
    for(i = 0; i < num; i++) {
        int start, end;
        get_int2(&start, &end);
        // 1-indexed -> 0-indexed
        start--; end--;
        ranges[i] = (struct range){start, end};
        // imos
        cnt[start]++;
        cnt[end]--;
    }

    for(i = 1; i < TIME_MAX; i++) {
        cnt[i] += cnt[i-1];
    }

    static struct pair seg[TIME2_MAX*2];
    // initialization
    for(i = 0; i < TIME_MAX; i++) {
        seg[i+TIME2_MAX].val = cnt[i];
    }
    for(i = TIME2_MAX-1; i >= ROOT_NODE; i--) {
        seg[i].val = max(seg[i*2].val, seg[i*2+1].val);
    }

    struct range whole = {0, TIME2_MAX};
    int ans = NUM_MAX+1;
    for(i = 0; i < num; i++) {
        struct range r = ranges[i];
        // remove
        add_range(seg, -1, r, ROOT_NODE, whole);
        ans = min(ans, get_cnt(seg, TIME2_MAX));
        // restore
        add_range(seg, 1, r, ROOT_NODE, whole);
    }
    printf("%d\n", ans);

    return 0;
}
