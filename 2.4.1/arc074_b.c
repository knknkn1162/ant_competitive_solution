#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define ARR_MAX 300000
#define BUF_SIZE (ARR_MAX*11+50)
#define DIVISOR 1000000007

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

#define HEAP_MAX (ARR_MAX+50)
int heap[HEAP_MAX];
int hidx = 1;

int cmp(int a1, int a2) {
    return a1 < a2;
}

void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

void enqueue(int num) {
    int node = hidx;
    heap[hidx++] = num;
    int parent;
    while((parent = node/2)) {
        if(cmp(heap[parent], heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
    return;
}

int dequeue_min(void) {
    int node = 1;
    int ans = heap[1];
    heap[1] = heap[--hidx];

    while(1) {
        int smallest = node;
        int left = node * 2;
        int right = node * 2 + 1;
        if(left < hidx && !cmp(heap[smallest], heap[left])) {
            smallest = left;
        }
        if(right < hidx && !cmp(heap[smallest], heap[right])) {
            smallest = right;
        }
        if(smallest == node) break;
        swap(&heap[smallest], &heap[node]);
        node = smallest;
    }
    return ans;
}

void reset_heap(void) {
    hidx = 1;
}

#define ANS_MIN INT64_MIN

void record(int *arr, int64_t *sum, int num) {
    reset_heap();
    sum[0] = arr[0];
    enqueue(arr[0]);
    int i;
    for(i = 1; i < num*2; i++) {
        int diff = arr[i];
        enqueue(arr[i]);
        if(i >= num) {
            int tmp = dequeue_min();
            diff -= tmp;
        }
        sum[i] = sum[i-1] + (int64_t)diff;
    }
    return;
}

int main(void) {
    static int arr[ARR_MAX];
    int num = get_int();
    int size = num*3;
    fget_array(arr, size);
    static int rarr[ARR_MAX];
    int i;

    // for using same priority heap
    for(i = 0; i < size; i++) rarr[i] = -arr[size-1-i];
    static int64_t sum[ARR_MAX];
    static int64_t rsum[ARR_MAX];

    record(arr, sum, num);
    record(rarr, rsum, num);

    int64_t ans = ANS_MIN;
    for(i = num-1; i < 2*num; i++) {
#ifdef DEBUG
        // sum of [0, .. , i](i) + [i+1, ... size](size-1-(i+1))
        printf("%lld %lld\n", sum[i], rsum[size-2-i]);
#endif
        ans = max(ans, sum[i] + rsum[size-2-i]);
    }
    printf("%lld\n", ans);

    return 0;
}
