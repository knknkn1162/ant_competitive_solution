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

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];
    fget_array(arr, num);

    int left;
    int right = 0;
    int sum = 0;
    uint64_t cnt = 0;
    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            if(sum & arr[right]) break;
            sum = sum ^ arr[right];
        }
#ifdef DEBUG
        printf("[%d] [%d, %d)\n", sum, left, right);
#endif
        cnt += (right - left);
        sum = sum ^ arr[left];
    }
    printf("%llu\n", cnt);
    return 0;
}
