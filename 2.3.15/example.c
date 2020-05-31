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

    static int dp[STR_MAX+1];
    static int64_t cum[26];
    static int sum = 0;
    dp[0] = 1;
    sum = 1;
    int i;
    for(i = 1; i <= len; i++) {
        char s = str[i-1];
        dp[i] = sum - cum[s-'a'];
        cum[s-'a'] += dp[i];
        sum += dp[i];
    }
    printf("%d\n", sum);
    return 0;
}
