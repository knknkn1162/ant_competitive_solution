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

int main(void) {
    int num, k;
    get_int2(&num, &k);
    int arr[NUM_MAX];
    fget_array(arr, num);
    int i;
    int ans = INF;
    for(i = k-1; i < num; i++) {
        int start = arr[i-(k-1)];
        int end = arr[i];
        int diff = min(abs(start), abs(end));
        ans = min(ans, diff + end-start);
    }
    printf("%d\n", ans);
    return 0;
}
