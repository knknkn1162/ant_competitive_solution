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

int main(void) {
    int num, t;
    // t is dummy
    get_int2(&num, &t);

    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    int mmax = arr[num-1];
    int diff = 0;
    int cnt = 1;
    for(i = num-2; i >= 0; i--) {
        int cur = arr[i];
        int profit = max(0, mmax - cur);
        if(diff < profit) {
            cnt = 1; // reset
            diff = profit;
        } else if (diff == profit) {
            cnt++;
        }
        mmax = max(cur, mmax);
    }

    printf("%d\n", cnt);
    return 0;
}
