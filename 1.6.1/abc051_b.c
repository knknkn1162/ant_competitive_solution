#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

#define ITEMS 3

#define K_MAX 2500
#define SUM_MAX (K_MAX*ITEMS)

void calc_cum(int *cum, int *dp, int limit) {
    int i;
    for(i = 1; i <= limit; i++) {
        cum[i] = cum[i-1] + dp[i-1];
    }
}

int main(void) {
    static int dp[ITEMS+1][SUM_MAX+1];
    static int cum[SUM_MAX+2];
    int limit, sum;
    get_int2(&limit, &sum);
    int i, j;
    for(i = 0; i <= min(limit, sum); i++) dp[1][i] = 1;
    calc_cum(cum, dp[1], sum+1);
    for(i = 2; i <= ITEMS; i++) {
        for(j = 0; j <= sum; j++) {
            // [j-2499, j]
            dp[i][j] = cum[j+1] - cum[max(0, j-limit)];
#ifdef DEBUG
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
#endif
        }
        calc_cum(cum, dp[i], sum+1);
    }

    printf("%d\n", dp[ITEMS][sum]);
    return 0;

}
