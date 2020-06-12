#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t
#include <math.h>

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

struct thing {
    int64_t pos;
    int idx;
    int type;
};

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(struct thing *arr, int type, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int64_t val;
        scanf("%lld", &val);
        arr[i] = (struct thing){.pos = val, .type = type, .idx = i};
    }
    return 0;
}

#define NUM_MAX 100000
#define QUERY_MAX 100000
#define SZ_MAX (NUM_MAX*2+QUERY_MAX)
#define INF (1e+14)

int asc(const void *a1, const void *a2) {
    struct thing *t1 = (struct thing*)a1;
    struct thing *t2 = (struct thing*)a2;
    if(t1->pos == t2->pos) {
        return t1->type - t2->type;
    }
    if(t1->pos > t2->pos) return 1;
    return -1;
}

enum type {
    TYPE_A,
    TYPE_B,
    TYPE_X,
};

int main(void) {
    int as, bs;
    get_int2(&as, &bs);
    int qs = get_int();
    static struct thing ts[SZ_MAX];
    fget_array(ts, TYPE_A, as);
    fget_array(&ts[as], TYPE_B, bs);
    fget_array(&ts[as+bs], TYPE_X, qs);
    int size = as + bs + qs;
    qsort(ts, size, sizeof(struct thing), asc);

    int64_t aprev = -INF;
    int64_t bprev = -INF;
    int i;
    static int64_t neighs[SZ_MAX]; // positive
    memset(neighs, 0x7f, sizeof(int64_t)*SZ_MAX);
    for(i = 0; i < size; i++) {
        struct thing t = ts[i];
        switch(t.type) {
            case TYPE_A:
                neighs[i] = min(neighs[i], labs(t.pos - bprev));
                aprev = t.pos;
                break;
            case TYPE_B:
                neighs[i] = min(neighs[i], labs(t.pos - aprev));
                bprev = t.pos;
                break;
            case TYPE_X:
            default:
                break;
        }
    }

    aprev = INF;
    bprev = INF;
    for(i = size-1; i >= 0; i--) {
        struct thing t = ts[i];
        switch(t.type) {
            case TYPE_A:
                neighs[i] = min(neighs[i], labs(t.pos - bprev));
                aprev = t.pos;
                break;
            case TYPE_B:
                neighs[i] = min(neighs[i], labs(t.pos - aprev));
                bprev = t.pos;
                break;
            case TYPE_X:
            default:
                break;
        }
    }
#ifdef DEBUG
    for(i = 0; i < size; i++) {
        printf("[%d]%lld ", ts[i].type, neighs[i]);
    }
    putchar('\n');
#endif

    int64_t prev_diff = INF;
    int64_t prev_pos = -INF;
    static int64_t ans[QUERY_MAX];
    memset(ans, 0x7f, sizeof(int64_t)*QUERY_MAX);
    for(i = 0; i < size; i++) {
        struct thing t = ts[i];
        switch(t.type) {
            case TYPE_A:
                // fall through
            case TYPE_B:
                prev_diff = neighs[i];
                prev_pos = ts[i].pos;
                break;
            case TYPE_X:
                ans[t.idx] = min(ans[t.idx], prev_diff+(t.pos-prev_pos));
                break;
            default:
                break;
        }
    }
    prev_diff = INF;
    prev_pos = -INF;
    for(i = size-1; i >= 0; i--) {
        struct thing t = ts[i];
        switch(t.type) {
            case TYPE_A:
                // fall through
            case TYPE_B:
                prev_diff = neighs[i];
                prev_pos = ts[i].pos;
                break;
            case TYPE_X:
                ans[t.idx] = min(ans[t.idx], prev_diff+labs(t.pos-prev_pos));
                break;
            default:
                break;
        }
    }
    
    for(i = 0; i < qs; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
