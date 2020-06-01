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

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    qsort(arr, num, sizeof(int), asc);

    int i;
    int bigger = arr[num-1];
    int smaller = 0;
    int arg = 0;
    for(i = 0; i < num-1; i++) {
        int target = min(bigger-arr[i], arr[i]);
        if(smaller < target) {
            smaller = target;
            arg = i;
        }
    }

    printf("%d %d\n", arr[num-1], arr[arg]);
    return 0;
}
