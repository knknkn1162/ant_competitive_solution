#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
  int64_t num;
  scanf("%lld", &num);
  return num;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

#define QUERY_MAX 200000
#define HEAP_MAX (QUERY_MAX+50)
static int64_t max_heap[HEAP_MAX];
static int hmax_idx = 1;
 
void swap(int64_t *a1, int64_t *a2) {
    int64_t tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}
 
int maxcmp(int64_t a1, int64_t a2) {
    return a1 > a2;
}
 
void enqueue_max(int64_t val) {
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
 
int64_t dequeue_max(void) {
    int64_t ans = max_heap[1];
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
static int64_t min_heap[HEAP_MAX];
static int hmin_idx = 1;

int mincmp(int64_t a1, int64_t a2) {
    return a1 < a2;
}

int is_min_heap_empty(void) {
    return hmin_idx == 1;
}
 
void enqueue_min(int64_t val) {
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
 
int64_t dequeue_min(void) {
    int64_t ans = min_heap[1];
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
int get_size(void) {
    return size;
}
// max_heap[1] <= min_heap[1]
void add(int64_t val, int k) {
    int64_t mmax = max_heap[1];
    if(size < k) {
        enqueue_max(val);
        size++;
        return;
    }
    if(val >= mmax) {
        enqueue_min(val);
    } else {
        enqueue_max(val);
        // move right
        int64_t nval = dequeue_max();
        enqueue_min(nval);
    }
    size++;
}

int64_t find_and_delete(int k) {
    if(size < k) {
        return -1;
    }
    int64_t ans = dequeue_max();
    if(!is_min_heap_empty()) {
        // move left
        int64_t nval = dequeue_min();
        enqueue_max(nval);
    }
    size--;
    return ans;
}

enum query {
    QUERY_ADD = 1,
    QUERY_GETK = 2
};

int main(void) {
    int num, k;
    get_int2(&num, &k);

    int i;
    int64_t ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < num; i++) {
        int type = get_int();
        switch(type) {
            case QUERY_ADD:
                {
                    int64_t val = get_int();
                    add(val, k);
                }
                break;
            case QUERY_GETK:
                {
                    ans[aidx++] = find_and_delete(k);
                }
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
