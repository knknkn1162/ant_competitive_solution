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

#define NUM_MAX 100

struct prod {
    int weight;
    int value;
};

#define RANGE_MAX 3
int main(void) {
    int num, ulimit;
    get_int2(&num, &ulimit);
    static struct prod prods[NUM_MAX];
    int i, j;
    for(i = 0; i < num; i++) {
        get_int2(&prods[i].weight, &prods[i].value);
    }
    int base = prods[0].weight;
    for(i = 0; i < num; i++) prods[i].weight -= base;

    int k, k0;
    // 100*100*(300) <= 3000000
    static int dp[NUM_MAX+1][NUM_MAX+1][RANGE_MAX*NUM_MAX+1];
    int mmax = RANGE_MAX*num;
    int ans = 0;
    for(k = 1; k <= 100; k++) {
        ulimit -= base;
        // too heavy
        if(ulimit < 0) break;
        memset(dp, 0, sizeof(int)*(NUM_MAX+1)*(NUM_MAX+1)*(RANGE_MAX*NUM_MAX+1));
        int ulim = min(ulimit, mmax);
        for(i = 1; i <= num; i++) {
            struct prod p = prods[i-1];
            for(k0 = 0; k0 <= k; k0++) {
                for(j = 0; j <= ulim; j++) {
                    dp[i][k0][j] = dp[i-1][k0][j]; // stay
                    if(j >= 1) dp[i][k0][j] = max(dp[i][k0][j], dp[i][k0][j-1]); // slide
                    if(j >= p.weight && k0 >= 1) {
                        dp[i][k0][j] = max(dp[i][k0][j], dp[i-1][k0-1][j-p.weight]+p.value);
                    }
                }
            }
        }
        ans = max(ans, dp[num][k][ulim]);
    }
    printf("%d\n", ans);
    return 0;
}
