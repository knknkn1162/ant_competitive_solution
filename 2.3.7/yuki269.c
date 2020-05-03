#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30


int get_int3(int *a1, int *a2, int *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d", a1, a2, a3);
#else
#error
#endif
  return 0;
}

#define SUM_MAX 20000
#define NUM_MAX 100
#define DIVISOR 1000000007

int main(void) {
    int num, sum, step;
    static uint64_t dp[SUM_MAX+1][NUM_MAX];

    get_int3(&num, &sum, &step);

    // calc num-1 split in sum-**
    dp[0][0] = 1;
    int s, n;
    for(s = 0; s <= sum; s++) {
        for(n = 1; n < num; n++) {
            dp[s][n] = dp[s][n-1];
            if(s>=n) dp[s][n] = (dp[s][n] + dp[s-n][n]) % DIVISOR;
        }
    }

    uint64_t ans = 0;
    int base;
    for(base = 0; base <= sum; base++) {
        int base_sum = num * base + step * num * (num-1)/2;
        if(base_sum > sum) break;
        int rem = sum - base_sum;
#ifdef DEBUG
        printf("[%d] dp[%d][%d] = %llu\n", base_sum, rem ,num-1, dp[rem][num-1]);
#endif
        ans = (ans + dp[rem][num-1]) % DIVISOR;
    }
    printf("%d\n", (int)ans);

    return 0;
}
