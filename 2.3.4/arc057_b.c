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

#define DAYS_MAX 2000

int main(void) {
    int days, wins;
    get_int2(&days, &wins);
    static int arr[DAYS_MAX];
    fget_array(arr, days);
    int sum = 0;
    int i;
    for(i = 0; i < days; i++) sum += arr[i];
    if(sum == wins) {
        printf("1\n");
        return 0;
    }

    // dp[days][wins] = min(K)
    static int dp[DAYS_MAX+1][DAYS_MAX+1];
    memset(dp, 0x7f, sizeof(int)*(DAYS_MAX+1)*(DAYS_MAX+1));
    for(i = 0; i <= days; i++) dp[i][0] = 0;
    dp[1][1] = 1;

    int d, w;
    sum = arr[0];
    for(d = 2; d <= days; d++) {
        int cur = arr[d-1];
        for(w = 1; w <= d; w++) {
            int64_t llimit = (int64_t)(sum + cur) * dp[d-1][w-1] / sum + 1;
            dp[d][w] = min(dp[d-1][w], llimit);
        }
        sum += cur;
    }

    for(i = days; i >= 0; i--) {
        if(dp[days][i] <= wins) {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
