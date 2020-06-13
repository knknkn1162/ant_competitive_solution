#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return strlen(str);
}
#define STR_MAX 100001
#define BUF_SIZE (STR_MAX+50)
#define DIVISOR 1000000007

int main(void) {
    static char str[BUF_SIZE];
    int snum = get_str(str, BUF_SIZE);
    if(snum == 1) {
        printf("3\n");
        return 0;
    }

    int i;
    // Case 1: considering the number which digits are all 1
    static int64_t dp[STR_MAX+2];
    dp[snum] = 1;
    for(i = snum-1; i >= 0; i--) {
        dp[i] = (dp[i+1] * 3)%DIVISOR;
    }

    int64_t ans = 0;
    int64_t prev = 1; // 0+0
    for(i = snum-1; i >= 0; i--) {
        // stay
        if(str[i] == '0') continue;
        ans = (dp[i+1] + prev * 2)%DIVISOR;
#ifdef DEBUG
        printf("%lld %lld\n", dp[i+1], prev);
#endif
        prev = ans;
    }
    printf("%d\n", (int)ans);
    return 0;
}
