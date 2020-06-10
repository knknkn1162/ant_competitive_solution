#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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
    COMMAND_FIND
};

#define NUM2_MAX (1<<17)
#define QUERY_MAX 100000
#include <limits.h>

struct range {
    int start;
    int end;
};

struct pair {
    int val;
    int time;
};
#define ROOT_NODE 1

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

void update_range(struct pair *seg, struct range r, struct pair val, int node, struct range nr) {
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node] = val;
#ifdef DEBUG
        printf("update: %d -> (%d, %d)\n", node, val.val, val.time);
#endif
        return;
    }
    struct range left = { nr.start, (nr.start + nr.end) / 2 };
    struct range right = { (nr.start + nr.end) / 2, nr.end };
    update_range(seg, r, val, node*2, left);
    update_range(seg, r, val, node*2+1, right);
    return;
}

struct pair find(struct pair *seg, int num2, int idx) {
    int node = num2 + idx;
    struct pair ans = seg[node];
    while((node = node/2)) {
        struct pair this = seg[node];
        ans = ans.time > this.time ? ans : this;
    }
    return ans;
}

int main(void) {
    int num, qs;
    get_int2(&num, &qs);
    int i;
    int num2 = 1;
    while(num > num2) num2 *= 2;
    // initialization
    static struct pair seg[NUM2_MAX*2];
    for(i = ROOT_NODE; i < num2*2; i++) seg[i] = (struct pair){.val = INT_MAX, .time = -1};
    struct range whole = {0, num2};
    static int ans[QUERY_MAX];
    int aidx = 0;
    int t;
    for(t = 0; t < qs; t++) {
        int type = get_int();
        switch(type) {
            case COMMAND_UPDATE:
                {
                    int start, end;
                    int val;
                    get_int3(&start, &end, &val);
                    end++;
                    struct range r = {start, end};
                    struct pair np = {val, t};
                    update_range(seg, r, np, ROOT_NODE, whole);
                }
                break;
            case COMMAND_FIND:
                {
                    int idx = get_int();
                    struct pair p = find(seg, num2, idx);
                    ans[aidx++] = p.val;
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
