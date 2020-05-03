#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define STR_MAX 300
#define BUF_SIZE (STR_MAX+50)

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int is_iwi(char *str) {
    return strncmp(str, "iwi", 3) == 0;
}

int main(void) {
    char str[BUF_SIZE];
    // size, start
    static int dp[STR_MAX+1][STR_MAX+1];
    get_str(str, BUF_SIZE);
    int len = strlen(str) - 1;
    int start, size;
    int i;
    for(size = 3; size <= len; size++) {
        // calc dp[size][start]
        for(start = 0; start <= len-size; start++) {
            int end = start + size;
            int start2;
            // [start2, start2+size-3)
            int res = 0;
            // split 2 ranges
            for(start2 = start+1; start2 < end; start2++) {
                res = max(res, dp[start2-start][start] + dp[end-start2][start2]);
            }
            for(start2 = start+1; start2 <= start+2; start2++) {
                char rem[4] = {0};
                int idx = 0;
                for(i = start; i < start2; i++) {
                    rem[idx++] = str[i];
                }
                for(i = start2+size-3; i < end; i++) {
                    rem[idx++] = str[i];
                }
                int tmp = dp[size-3][start2];
                int is_empty = ((tmp*3) == (size-3));
                res = max(res, is_empty ? tmp + is_iwi(rem) : tmp);
                }
            dp[size][start] = res;
#ifdef DEBUG
            printf("dp[%d][%d] = %d\n", size, start, dp[size][start]);
#endif
        }
    }
    printf("%d\n", dp[len][0]);
    return 0;
}
