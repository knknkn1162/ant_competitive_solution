#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define DIVISOR 1000000007

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

#define HIGH_MAX ((uint64_t)(1e+18))+1
#define NUM_MAX 30000

int count_smaller(int *arr, int *brr, int size, uint64_t key) {
    int i;
    int counter = 0;
    for(i = 0; i < size; i++) {
        int low = -1;
        int high = size;
        uint64_t a = arr[i];
        while(low + 1 < high) {
            int mid = (low + high)/2;
            uint64_t sum = a * (uint64_t)brr[mid];
            if(sum < key) {
                low = mid;
            } else {
                high = mid;
            }
        }
        counter += (low + 1);
    }
    return counter;
}

int asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int num, k;
    int arr[NUM_MAX];
    int brr[NUM_MAX];
    get_int2(&num, &k);
    fget_array(arr, num);
    fget_array(brr, num);
    qsort(arr, num, sizeof(int), asc);
    qsort(brr, num, sizeof(int), asc);

    uint64_t low = 0;
    uint64_t high = HIGH_MAX;

    while(low + 1 < high) {
        uint64_t mid = (low + high)/2;
        int count = count_smaller(arr, brr, num, mid);
        if(count < k) {
            low = mid;
        } else {
            high = mid;
        }
#ifdef DEBUG
        printf("%d %lld %lld\n", count, low, high);
#endif
    }
    printf("%llu\n", low);
    return 0;
}
