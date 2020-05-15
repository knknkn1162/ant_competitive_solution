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

int get_int2(int64_t *a1, int *a2) {
  scanf("%lld %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int64_t *a2, int *a3) {
  scanf("%d %lld %d", a1, a2, a3);
  return 0;
}

struct monster {
    int64_t pos;
    int hp;
};

int asc_by_pos(const void *a1, const void *a2) {
    struct monster *ma1 = (struct monster*)a1;
    struct monster *ma2 = (struct monster*)a2;
    return ma1->pos - ma2->pos;
}

#define NUM_MAX 200000
#define NUM2_MAX (1<<18)
#define ROOT_NODE 1
#define INF ((int64_t)(3e+9)+1)

struct range {
    int start;
    int end;
};

int64_t get_val(int64_t* seg, int num, int idx) {
    int node = num+idx;
    int64_t ans = 0;
    while(node) {
        ans += seg[node];
        node /= 2;
    }
    return ans;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && box.end >= this.end;
}

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

void add_range(int64_t *seg, int64_t val, struct range r, int node, struct range nr) {
#ifdef DEBUG
    printf("add_range(seg, %lld, r, %d)\n", val, node);
#endif
    if(is_contain(nr, r)) {seg[node] += val; return;}
    if(!is_overlap(r, nr)) return;
    struct range left = {nr.start, (nr.start+nr.end)/2};
    struct range right = {left.end+1, nr.end};
    add_range(seg, val, r, node*2, left);
    add_range(seg, val, r, node*2+1, right);
    return;
}

#define ROOT_NODE 1
int main(void) {
    int num, attack;
    int64_t range;
    static struct monster mons[NUM_MAX+1];
    get_int3(&num, &range, &attack);
    range *= 2;
    int num2 = 1;
    while(num > num2) num2 *= 2;

    int i;
    for(i = 0; i < num; i++) {
        get_int2(&mons[i].pos, &mons[i].hp);
    }
    mons[num] = (struct monster){INF, 0}; // guard
    qsort(mons, num, sizeof(struct monster), asc_by_pos);

    static int64_t seg[NUM2_MAX*2];
    for(i = 0; i < num; i++) {
        seg[i+num2] = mons[i].hp;
    }

    int left;
    int right = 0;
    int64_t ans = 0;
    static int map[NUM_MAX+1];

    struct range whole = {0, num2-1};
    for(left = 0; left < num+1; left++) {
        if(left == right) { right++; }
        int64_t rem = get_val(seg, num2, left);
        if(rem <= 0) continue; // if no hit point, break;
        // ensure that mons[left] should be attacked
        for(right = 0; right < num+1; right++) {
            if(mons[left].pos + range < mons[right].pos) break;
        }
#ifdef DEBUG
        printf("[%d, %d)\n", left, right);
#endif
        // attack
        int64_t cnt = (rem-1)/attack + 1;
        int64_t damage = (int64_t)attack * cnt;
        struct range r = {left, right-1};
        add_range(seg, -damage, r, ROOT_NODE, whole);
        map[left]++;
        map[right]++;
        ans += cnt;
    }
    printf("%lld\n", ans);

    return 0;
}
