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

int lower_bound(int *arr, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];
    fget_array(arr, num);

    int qs = get_int();
    int i;
    int ans = 0;
    for(i = 0; i < qs; i++) {
        int q = get_int();
        int idx = lower_bound(arr, num, q);
        if(idx == num) continue;
        ans += (arr[idx] == q);
    }

    printf("%d\n", ans);
    return 0;
}
