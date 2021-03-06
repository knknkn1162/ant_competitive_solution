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
#define NUM_MAX 200000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    for(i = 0; i < num; i++) {
        arr[i] -= i;
    }
    qsort(arr, num, sizeof(int), asc);
    int mid = arr[num/2];

    int64_t ans = 0;
    for(i = 0; i < num; i++) {
        ans += abs(arr[i]-mid);
    }
    printf("%lld\n", ans);
    return 0;
}
