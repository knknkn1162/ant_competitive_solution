/*
M
n m

ex)
10000
4 3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20

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

#define LIMIT_MAX 1000
#define NUM_MAX 1000

int main(void) {
    int divisor = get_int();
    static int dp[NUM_MAX+1][LIMIT_MAX+1];
    int num, limit;
    int i;
    get_int2(&num, &limit);
    dp[0][0] = 1;
    int n, lim;
    // assume that
    // a_1 + a_2 + a_3 = n (a_i >= 0)
    // separate 2 cases -> a_i > 0 for all i and a_i>=0 in i
    for(n = 0; n <= num; n++) {
        for(lim = 1; lim <= limit; lim++) {
            dp[n][lim] = dp[n][lim-1];
            if(n-lim>=0) dp[n][lim] = (dp[n][lim] + dp[n-lim][lim])%divisor;
        }
    }
    printf("%d\n", dp[num][limit]);
    return 0;
}
