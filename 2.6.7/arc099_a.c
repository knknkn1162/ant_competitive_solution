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
#define INF (NUM_MAX+1)

int main(void) {
    int num, size;
    get_int2(&num, &size);
    static int arr[NUM_MAX];
    fget_array(arr, num);
    num -= size;
    int cnt = 1;
    while(num>0) {
        num -= (size-1);
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
