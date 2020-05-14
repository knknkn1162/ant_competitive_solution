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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 20000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

static int heap[NUM_MAX+5];
int hidx = 1;

int is_one(void) {
    return hidx == 2;
}

int cmp(int a, int b) {
    return a < b;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void enqueue(int elem) {
    int node = hidx;
    heap[hidx++] = elem;
    int parent;
    while((parent = node/2)) {
        if(cmp(heap[parent], heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
}

int get_min(void) {
    int ans = heap[1];
    heap[1] = heap[--hidx];
    int node = 1;
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

int main(void) {
    int num = get_int();
    fget_array(&heap[1], num);
    qsort(&heap[1], num, sizeof(int), asc);
    hidx = num+1;

    int64_t sum = 0;
    while(!is_one()) {
        int len1 = get_min();
        int len2 = get_min();
#ifdef DEBUG
        printf("%d + %d\n", len1, len2);
#endif
        int len = len1 + len2;
        sum += len;
        enqueue(len);
    }
    printf("%lld\n", sum);
    return 0;
}
