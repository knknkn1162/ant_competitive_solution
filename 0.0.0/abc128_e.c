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

struct range {
    int start;
    int end;
};

struct work {
    struct range r;
    int pos;
};

int asc(const void *a1, const void *a2) {
    struct work *w1 = (struct work*)a1;
    struct work *w2 = (struct work*)a2;
    return w1->pos - w2->pos;
}

#define NUM_MAX 200000
#define ROOT_NODE 1
#define QUERY_MAX 200000

typedef int (*CMP)(int, int);

int lower_bound(int *arr, int num, CMP func, int key) {
    int low = -1;
    int high = num;
    while(low + 1 < high) {
        int mid =(low + high) / 2;
        if(func(arr[mid], key)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int gt(int x, int a) {
    return x > a;
}
int ge(int x, int a) {
    return x >= a;
}

int main(void) {
    int num, qs;
    get_int2(&num, &qs);
    static struct work works[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        int start, end, pos;
        get_int3(&start, &end, &pos);
        works[i] = (struct work){
            {max(start-pos, 0), max(end-pos, 0)}, pos
        };
    }
    qsort(works, num, sizeof(struct work), asc);
    static int start[NUM_MAX];
    static int end[NUM_MAX];
    start[0] = works[0].r.start;
    end[0] = works[0].r.end;
    for(i = 1; i < num; i++) {
        struct work w = works[i];
        // decreasing
        start[i] = min(start[i-1], w.r.start);
        // increasing
        end[i] = max(end[i-1], w.r.end);
    }
    static int inv_start[NUM_MAX];
    for(i = 0; i < num; i++) inv_start[i] = -inv_start[i];

    static int ans[QUERY_MAX];
    for(i = 0; i < qs; i++) {
        int q = get_int();
        int idx;
        if(q < start[0]) {
            // greater than or equal
            idx = lower_bound(inv_start, num, ge, -q);
        } else {
            // greater than
            idx = lower_bound(end, num, gt, q);
        }
#ifdef DEBUG
        printf("key: %d -> %d\n", q, idx);
#endif
        if(idx >= num) {
            ans[i] = -1;
        } else {
            ans[i] = works[idx].pos;
        }
    }

    for(i = 0; i < qs; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
