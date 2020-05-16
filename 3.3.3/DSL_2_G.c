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
    int sum;
    int lazy_sum;
};

struct range {
    int start;
    int end;
};

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)

#define ROOT_NODE 1

int is_overlap(struct range r1, struct range r2) {
    if(r1.end > r2.start && r2.end > r1.start) {
        return min(r1.end-r2.start, r2.end-r1.start);
    }
    return 0;
}

int is_contain(struct range elem, struct range box) {
    return elem.start >= box.start && elem.end <= box.end;
}

void add_range(struct pair *seg, int val, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node].lazy_sum += val;
    } else {
        struct range left = { nr.start, (nr.start+nr.end)/2 };
        struct range right = { (nr.start+nr.end)/2, nr.end };
        add_range(seg, val, r, node*2, left);
        add_range(seg, val, r, node*2+1, right);
    }
    return;
}

int get_sum(struct pair *seg, struct range r, int node, struct range nr) {
    int cnt = is_overlap(r, nr);
#ifdef DEBUG
    printf("get_sum(%d, (%d, %d))\n", cnt, nr.start, nr.end);
#endif
    if(!cnt) return 0;
    if(is_contain(nr, r)) return seg[node].sum + seg[node].lazy_sum*cnt;

    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    int s1 = get_sum(seg, r, node*2, left);
    int s2 = get_sum(seg, r, node*2+1, right);
    return s1 + s2 + seg[node].lazy_sum * cnt;
}


int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    int i;
    static struct pair seg[NUM2_MAX];
    static int ans[NUM_MAX];
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
        printf("%d\n", ans[i]);
    }

    return 0;
}
