#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

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

struct ss {
    int width;
    int important;
};

#define NUM_MAX 50
#define WIDTH_MAX 10000

int main(void) {
    int width = get_int();
    static struct ss ss[NUM_MAX];
    int num, k;
    int i, j, w, n;
    static int dp[NUM_MAX+1][NUM_MAX+1][WIDTH_MAX+1];
    // do[0][0][0]
    get_int2(&num, &k);

    for(i = 0; i < num; i++) {
        get_int2(&ss[i].width, &ss[i].important);
    }

    for(n = 1; n <= num; n++) {
        int wid = ss[n-1].width;
        int imp = ss[n-1].important;
        int min_j = min(n,k);
        for(j = 1; j <= min_j; j++) {
            for(w = 0; w <= width; w++) {
                // take over
                dp[n][j][w] = dp[n][j][w-1];
                // not select
                if(n>j) dp[n][j][w] = dp[n-1][j][w];
                // select
                if(w>=wid) dp[n][j][w] = max(dp[n][j][w], dp[n-1][j-1][w-wid] + imp);
            }
        }
#ifdef DEBUG
        for(j = 1; j <= min_j; j++) {
            printf("%d ", dp[n][j][width]);
        }
        putchar('\n');
#endif
    }
    int ans = 0;
    for(i = 0; i <= k; i++) {
#ifdef DEBUG
        printf("%d: %d\n", i, dp[num][i][width]);
#endif
        ans = max(ans, dp[num][i][width]);
    }
    printf("%d\n", ans);
    return 0;
}
