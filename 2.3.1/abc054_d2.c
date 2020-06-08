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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}


struct prod {
    int a;
    int b;
    int cost;
};

#define NUM_MAX 40
// 99*40
#define INF 0x01010101
#define A_MAX 10
#define B_MAX 10
#define SA_MAX (A_MAX*NUM_MAX)
#define SB_MAX (B_MAX*NUM_MAX)

int main(void) {
    int num = get_int();
    int ma, mb;
    static struct prod prods[NUM_MAX];
    get_int2(&ma, &mb);

    int i;
    for(i = 0; i < num; i++) {
        int a, b, cost;
        get_int3(&a, &b, &cost);
        prods[i] = (struct prod){a, b, cost};
    }

    static int dp[NUM_MAX+1][SA_MAX+1][SB_MAX+1];
    memset(dp, 0x01, sizeof(int)*(NUM_MAX+1)*(SA_MAX+1)*(SB_MAX+1));
    dp[0][0][0] = 0;
    int a, b;
    for(i = 1; i <= num; i++) {
        struct prod prod = prods[i-1];
        for(a = 0; a <= SA_MAX; a++) {
            for(b = 0; b <= SB_MAX; b++) {
                // stay
                dp[i][a][b] = min(dp[i][a][b], dp[i-1][a][b]);
                if(a >= prod.a && b >= prod.b) {
                    // choose
                    dp[i][a][b] = min(dp[i][a][b], dp[i-1][a-prod.a][b-prod.b]+prod.cost);
                }
            }
        }
    }
    int ans = INF;
    for(i = 1; i <= SA_MAX; i++) {
        int a = i*ma;
        int b = i*mb;
        if(a > SA_MAX || b > SB_MAX) break;
        ans = min(ans, dp[num][a][b]);
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
