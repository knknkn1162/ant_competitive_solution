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
        arr[i]++;
    }
    return 0;
}

int lower_bound(int *dp, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high)/2;
        // lower bound
        if(dp[mid] >= key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

#define NUM_MAX 100000

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];
    // dp[len] = <smallest value>
    static int dp[NUM_MAX+1];
    int idx = 1;
    fget_array(arr, num);

    int i;
    for(i = 1; i <= num; i++) {
        int val = arr[i-1];
        if(dp[idx-1] < val) {
            dp[idx++] = val;
        } else {
            int nidx = lower_bound(dp, idx, val);
#ifdef DEBUG
            printf("[%d] %d -> %d\n", i, idx, nidx);
#endif
            dp[nidx] = val;
        }
    }
    printf("%d\n", idx-1);
    return 0;
}
