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

struct box {
    int width;
    int height;
};

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)
#define WIDTH_MAX 100000

// already sorted
int asc_by_height(const void *a1, const void *a2) {
    struct box *ba1 = (struct box*)a1;
    struct box *ba2 = (struct box*)a2;
    if(ba1->height == ba2->height) {
        return ba2->width - ba1->width;
    }
    return ba1->height - ba2->height;
}

struct range {
    int start;
    int end;
};

#define ROOT_NODE 1

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

int is_contain(struct range elem, struct range box) {
    return box.start <= elem.start && box.end >= elem.end;
}

int get_max(int *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    struct range left = { nr.start, (nr.start+nr.end)/2 };
    struct range right = { left.end+1, nr.end };
    int m1 = get_max(seg, r, node*2, left);
    int m2 = get_max(seg, r, node*2+1, right);
    return max(m1, m2);
}

void update(int *seg, int num, int idx, int val) {
    int node = num + idx;
    seg[node] = val;
    while((node = node/2)) {
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }
    return;
}

int main(void) {
    int num = get_int();
    int i;
    static struct box boxes[NUM_MAX];

    for(i = 0; i < num; i++) {
        get_int2(&boxes[i].width, &boxes[i].height);
    }

    qsort(boxes, num, sizeof(struct box), asc_by_height);

    // seg[width] = <cnt>
    static int seg[NUM2_MAX*2];

    struct range whole = {0, NUM2_MAX-1};
    for(i = 0; i < num; i++) {
        int cur = boxes[i].width;
        struct range r = {0, cur-1};
        int new = get_max(seg, r, ROOT_NODE, whole) + 1;
#ifdef DEBUG
        printf("%d -> %d\n", cur, new);
#endif
        if(new > seg[NUM2_MAX+cur]) {
            update(seg, NUM2_MAX, cur, new);
        }
    }
    printf("%d\n", seg[ROOT_NODE]);
    return 0;
}
