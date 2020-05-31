#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}
#define STR_MAX (100000+50)
#define DIVISOR 1000000007

int main(void) {
    static char str[STR_MAX];
    get_str(str, STR_MAX);
    int len = strlen(str);

    // e.g) aba : next_idx[1][a] = 3
    static int next_idx[STR_MAX+1][26];

    int i, ch;
    for(i = len; i >= 1; i--) {
        int idx = str[i-1]-'a';
        // next_idx[len][*] = 0;
        // next_idx[len-1][j] = (str[len-1] == j) ? i : next_idx[len][j]
        for(ch = 0; ch < 26; ch++) next_idx[i-1][ch] = next_idx[i][ch];
        next_idx[i-1][idx] = i;
    }

    static int dp[STR_MAX+1];
    dp[0] = 1;
    for(i = 0; i <= len; i++) {
        for(ch = 0; ch < 26; ch++) {
            if(next_idx[i][ch]) dp[next_idx[i][ch]] += dp[i];
        }
    }

    int sum = 0;
    for(i = 0; i <= len; i++) {
#ifdef DEBUG
        printf("dp[%d] = %d\n", i, dp[i]);
#endif
        sum += dp[i];
    }
    printf("%d\n", sum);
    return 0;
}
