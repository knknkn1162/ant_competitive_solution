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

enum query {
    QUERY_UPDATE = 1,
    QUERY_VALUE = 2,
};

#define NUM_MAX 200000
#define HEAP_MAX (NUM_MAX/2 + 50)
static int max_heap[NUM_MAX];
static int hmax_idx = 1;

void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

int maxcmp(int a1, int a2) {
    return a1 > a2;
}

void enqueue_max(int val) {
    int node = hmax_idx;
    max_heap[hmax_idx++] = val;
    int parent;
    while((parent = node / 2)) {
        if(maxcmp(max_heap[parent], max_heap[node])) break;
        swap(&max_heap[parent], &max_heap[node]);
        node = parent;
    }
    return;
}

int remove_max(void) {
    int ans = max_heap[1];
    max_heap[1] = max_heap[--hmax_idx];
    int node = 1;
    while(1) {
        int this = node;
        int left = node * 2;
        int right = node * 2 + 1;
        if(left < hmax_idx && !maxcmp(max_heap[this], max_heap[left])) {
            this = left;
        }
        if(right < hmax_idx && !maxcmp(max_heap[this], max_heap[right])) {
            this = right;
        }
        if(this == node) break;
        swap(&max_heap[this], &max_heap[node]);
        node = this;
    }
    return ans;
}


// min heap
static int min_heap[NUM_MAX];
static int hmin_idx = 1;

int mincmp(int a1, int a2) {
    return a1 < a2;
}

void enqueue_min(int val) {
    int node = hmin_idx;
    min_heap[hmin_idx++] = val;
    int parent;
    while((parent = node / 2)) {
        if(mincmp(min_heap[parent], min_heap[node])) break;
        swap(&min_heap[parent], &min_heap[node]);
        node = parent;
    }
    return;
}

int remove_min(void) {
    int ans = min_heap[1];
    min_heap[1] = min_heap[--hmin_idx];
    int node = 1;
    while(1) {
        int this = node;
        int left = node * 2;
        int right = node * 2 + 1;
        if(left < hmin_idx && !mincmp(min_heap[this], min_heap[left])) {
            this = left;
        }
        if(right < hmin_idx && !mincmp(min_heap[this], min_heap[right])) {
            this = right;
        }
        if(this == node) break;
        swap(&min_heap[this], &min_heap[node]);
        node = this;
    }
    return ans;
}

int size = 0;
int mmax = 0;
int mmin = 0;
int64_t mid_sum = 0;
void update(int val) {
    if(val >= mmax) enqueue_max(val);
    if(val <= mmin) enqueue_min(val);
    if(size%2 == 1) {
        remove_max();
        remove_min();
    }
    size++;
    if(size == 1) {
        mmax = mmin = val;
    } else {
        if(mmax <= val && val <= mmin) {
            // do nothing
        } else {
            mid_sum += min(abs(mmax-val), abs(mmin-val));
        }
    }
    // update
    mmax = max_heap[1];
    mmin = min_heap[1];
#ifdef DEBUG
    printf("update: %d %d -> %lld\n", mmax, mmin, mid_sum);
#endif
    return;
}

#define QUERY_MAX NUM_MAX
struct pair {
    int64_t med;
    int64_t sum;
};


int main(void) {
    int qs = get_int();
    int i;

    int64_t base = 0;
    static struct pair ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < qs; i++) {
        int type = get_int();
        switch(type) {
            case QUERY_UPDATE:
                {
                    int a, b;
                    get_int2(&a, &b);
                    update(a);
                    base += b;
                }
                break;
            case QUERY_VALUE:
                ans[aidx++] = (struct pair){mmax, mid_sum+base};
                break;
            default:
                break;
        }
    }

    for(i = 0; i < aidx; i++) {
        printf("%lld %lld\n", ans[i].med, ans[i].sum);
    }
    return 0;
}
