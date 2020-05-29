#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
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
#define INF (1e+9)

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num, selects;
    get_int2(&num, &selects);
    int arr[NUM_MAX];
    fget_array(arr, num);
    qsort(arr, num, sizeof(int), asc);

    int i;
    int ans = INF;
    for(i = selects-1; i < num; i++) {
        ans = min(ans, arr[i] - arr[i-selects+1]);
    }
    printf("%d\n", ans);
    return 0;
}
