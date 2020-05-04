#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define min3(a,b,c) min(min(a,b),c)
#define STR_MAX 1000
#define BUF_SIZE (STR_MAX+50)

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int main(void) {
    char str1[BUF_SIZE];
    char str2[BUF_SIZE];
    get_str(&str1[1], BUF_SIZE);
    get_str(&str2[1], BUF_SIZE);
    int len1 = strlen(&str1[1])-1;
    int len2 = strlen(&str2[1])-1;
#ifdef DEBUG
    printf("%d %d\n", len1, len2);
#endif
    static int dp[STR_MAX+1][STR_MAX+1];

    int i, j;
    for(i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for(i = 0; i <= len2; i++) {
        dp[0][i] = i;
    }

    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            dp[i][j] = min3(
                dp[i-1][j-1] + (str1[i] != str2[j]),
                dp[i][j-1] + 1,
                dp[i-1][j] + 1
            );
#ifdef DEBUG
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
#endif
        }
    }
    printf("%d\n", dp[len1][len2]);
    return 0;
}
