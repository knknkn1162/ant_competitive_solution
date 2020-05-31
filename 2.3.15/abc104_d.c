#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define STR_MAX 100000
#define BUF_SIZE (STR_MAX+50)

#define DIVISOR 1000000007

static char abc[] = "ABC";

int main(void) {
    static char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int len = strlen(str);

    static int64_t dp[4][STR_MAX+1];
    dp[0][0] = 1;
    int i, s;
    for(i = 1; i <= len; i++) {
        int wild_coff = str[i-1]=='?' ? 3 : 1;
        dp[0][i] = (dp[0][i-1]*wild_coff)%DIVISOR;
    }

    for(i = 1; i <= 3; i++) {
        for(s = 1; s <= len; s++) {
            char cur = str[s-1];
            int wild_coff = (cur == '?') ? 3 : 1;
            dp[i][s] = (dp[i][s] + dp[i][s-1]*wild_coff)%DIVISOR;
            if(cur=='?' || cur == abc[i-1]) {
                dp[i][s] = (dp[i][s] + dp[i-1][s-1])%DIVISOR;
            }
#ifdef DEBUG
            printf("dp[%d][%d] = %lld\n", i, s, dp[i][s]);
#endif
        }
    }

    printf("%d\n", (int)dp[3][len]);

    return 0;
}
