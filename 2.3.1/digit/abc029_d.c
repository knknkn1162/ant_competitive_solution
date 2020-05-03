#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define DIGIT_MAX 10
#define BUF_SIZE 15

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int main(void) {
    static uint64_t digit_dp[DIGIT_MAX+1][10];
    char nstr[BUF_SIZE];
    get_str(nstr, BUF_SIZE);
    int len = strlen(nstr) - 1;
#ifdef DEBUG
    printf("len: %d\n", len);
#endif
    digit_dp[1][1] = 1;
    uint64_t sum = 1;
    uint64_t whole = 10;

    int i, j;
    for(i = 2; i <= len; i++) {
        uint64_t tmp = 0;
        for(j = 0; j <= 9; j++) {
            digit_dp[i][j] = sum + (j==1)*whole;
            tmp += digit_dp[i][j];
#ifdef DEBUG
            printf("dp[%d][%d] = %llu\n", i, j, digit_dp[i][j]);
#endif
        }
        whole *= 10;
        sum = tmp;
    }

    uint64_t res = 0;
    for(i = len; i >= 1; i--) {
        int ch = nstr[len-i] - '0';
        for(j = 0; j < ch; j++) {
            res += digit_dp[i][j];
        }
        // In N=135, increment from 100 to 135
        if(ch == 1) {
            res += atol(&nstr[len-i+1]) + 1;
        }
    }
    printf("%llu\n", res);
    return 0;
}
