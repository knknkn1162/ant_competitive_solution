#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE (1000000+50)

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int main(void) {
    static char nstr[BUF_SIZE];
    // dp[digits][carry]
    static int dp[BUF_SIZE][2];
    nstr[0] = '0'; // guard
    get_str(&nstr[1], BUF_SIZE);
    int len = strlen(nstr) - 1;

    int i;
    int d0 = nstr[len-1] - '0';
    dp[1][0] = d0;
    dp[1][1] = 10 - d0;

#ifdef DEBUG
    printf("[%d] %d vs %d\n", 1, dp[1][0], dp[1][1]);
#endif

    for(i = 2; i <= len; i++) {
        int ch = nstr[len-i] - '0';
        dp[i][0] = min(
            dp[i-1][0] + ch,
            // carry
            dp[i-1][1] + (ch+1)
        );
        dp[i][1] = min(
            dp[i-1][0] + (10-ch),
            dp[i-1][1] + (9-ch)
        );
#ifdef DEBUG
        printf("[%d] %d vs %d\n", i, dp[i][0], dp[i][1]);
#endif
    }
    printf("%d\n", dp[len][0]);
    return 0;
}
