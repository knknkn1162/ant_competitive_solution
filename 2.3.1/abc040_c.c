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
int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    fget_array(&arr[1], num);
    static int dp[NUM_MAX+1];
    int i;
    // dp[1] = 0;
    for(i = 2; i <= num; i++) {
        int cur = arr[i];
        int prev = arr[i-1];
        dp[i] = dp[i-1] + abs(cur-prev);

        if(i >= 3) {
            int pprev = arr[i-2];
            dp[i] = min(dp[i], dp[i-2] + abs(cur-pprev));
        }
    }
    printf("%d\n", dp[num]);
    return 0;
}
