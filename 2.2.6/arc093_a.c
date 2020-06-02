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

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+2];
    int i;
    fget_array(&arr[1], num);
    arr[0] = arr[num+1] = 0;

    int64_t sum = 0;
    for(i = 1; i < num+2; i++) {
        sum += abs(arr[i] - arr[i-1]);
    }

    int64_t ans[NUM_MAX+1];
    for(i = 1; i <= num; i++) {
        ans[i] = sum - abs(arr[i+1] - arr[i]) - abs(arr[i] - arr[i-1]) + abs(arr[i+1] - arr[i-1]);
    }

    // presentation
    for(i = 1; i <= num; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
