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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 1000
#define K_MAX 3000
#define INF (1e+15)

// sort
int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}

#define HEAP_MAX (K_MAX*10)
void swap(int64_t *a1, int64_t *a2) {
    int64_t tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
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
int update(int64_t new, int k) {
#ifdef DEBUG
    printf("update(%lld)\n", new);
#endif
    if(k > size) {
        enqueue_min(new);
        size++;
        return 1;
    }
    int64_t mmin = min_heap[1];
    if(new <= mmin) return 0;
    enqueue_min(new);
    dequeue_min();
    return 1;
}



int main(void) {
    int xs, ys, zs;
    get_int3(&xs, &ys, &zs);
    int ord = get_int();

    int i, j, k;
    static int64_t xrr[NUM_MAX+1];
    static int64_t yrr[NUM_MAX+1];
    static int64_t zrr[NUM_MAX+1];
    fget_array(xrr, xs);
    fget_array(yrr, ys);
    fget_array(zrr, zs);
    xrr[xs] = yrr[ys] = zrr[zs] = -INF;
    qsort(xrr, xs, sizeof(int64_t), desc);
    qsort(yrr, ys, sizeof(int64_t), desc);
    qsort(zrr, zs, sizeof(int64_t), desc);

    for(i = 0; i < xs; i++) {
        for(j = 0; j < ys; j++) {
            int64_t sum = xrr[i] + yrr[j];
            for(k = 0; k < zs; k++) {
                int64_t sum3 = sum + zrr[k];
                if(!update(sum3, ord)) break;
            }
        }
    }

    qsort(&min_heap[1], ord, sizeof(int64_t), desc);
    for(i = 1; i <= ord; i++) {
        printf("%lld\n", min_heap[i]);
    }
    return 0;
}
