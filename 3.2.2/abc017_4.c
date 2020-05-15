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
#define KINDS_MAX 100000
#define DIVISOR 1000000007

int main(void) {
    int num, kinds;
    static int arr[NUM_MAX+1];
    static int64_t dp[NUM_MAX+1];
    static char map[KINDS_MAX+1];
    get_int2(&num, &kinds);
    dp[0] = 1;
    int64_t sum = 0;
    fget_array(&arr[1], num);
    int left;
    int right = 1;
    for(left = 1; left <= num; left++) {
        for(; right <= num; right++) {
            if(map[arr[right]]) break;
            map[arr[right]]++;
            sum = (sum + dp[right-1])%DIVISOR;
            dp[right] = sum;
#ifdef DEBUG
            printf("[%d, %d] -> %lld\n", left, right, dp[right]);
#endif
        }
        map[arr[left]]--;
        sum = (sum + DIVISOR - dp[left-1])%DIVISOR;
    }
    printf("%d\n", (int)dp[num]);
    return 0;
}
