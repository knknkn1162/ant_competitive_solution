#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

int judge(int *arr, int num, int key) {
    int low = -1;
    int high = num;
    int flag = 0;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            flag = 1;
            break;
        } else if (arr[mid] > key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return flag;
}

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];
    fget_array(arr, num);

    int qs = get_int();
    int i;
    int cnt = 0;
    for(i = 0; i < qs; i++) {
        int q = get_int();
        cnt += judge(arr, num, q);
    }

    printf("%d\n", cnt);
    return 0;
}
