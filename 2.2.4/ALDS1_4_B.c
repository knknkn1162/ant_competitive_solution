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

#define NUM_MAX 100000
#define QUERY_MAX 50000

int asc(const void *a1, const void *a2) { return *(int*)a1 - *(int*)a2; }

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    fget_array(arr, num);
    arr[num] = -1;
    int idx = 0;
    int prev = arr[0];
    int q, i;
    // unique
    for(i = 1; i < num+1; i++) {
        if(prev != arr[i]) arr[idx++] = prev;
        prev = arr[i];
    }
#ifdef DEBUG
    for(i = 0; i < idx; i++) printf("%d ", arr[i]);
    putchar('\n');
#endif
    int queries[QUERY_MAX];
    int qs = get_int();
    fget_array(queries, qs);

    qsort(queries, qs, sizeof(int), asc);

    int ans = 0;
    i = 0;
    for(q = 0; q < qs; q++) {
        for(; i < idx; i++) {
            if(arr[i] > queries[q]) break;
            ans += (arr[i] == queries[q]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
