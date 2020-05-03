#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 50

int get_str2(char *a1, char *a2, int size) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%s %s", a1, a2);
#else
#error
#endif
  return 0;
}

#define DIGIT_MAX 19

static uint64_t digit_dp[DIGIT_MAX+1][10];
static uint64_t power10[DIGIT_MAX+1];

void init_digit_dp(void) {
    //when digit_dp[1][*]
    digit_dp[1][4] = 1; digit_dp[1][9] = 1;
    uint64_t sum = 2;
    uint64_t whole = 10;
    int i, j;
    for(i = 2; i <= DIGIT_MAX; i++) {
        uint64_t tmp = 0;
        for(j = 0; j <= 9; j++) {
            digit_dp[i][j] = (j == 4 || j == 9) ? whole : sum;
            tmp += digit_dp[i][j];
        }
        whole *= 10;
        sum = tmp;
    }

    power10[0] = 1;
    for(i = 1; i <= DIGIT_MAX; i++) {
        power10[i] = power10[i-1] * 10;
    }

    return;
}
uint64_t count_number(char *nstr, int size) {
    int i, j;
    uint64_t res = 0;
    for(i = size; i >= 1; i--) {
        char ch = nstr[size-i] - '0';
        for(j = 0; j < ch; j++) {
            res += digit_dp[i][j];
        }
        // all numbers below 10**$(size) digit
        if(ch == 4 || ch == 9) {
            // when i=1 -> '\0'
            res += atol(&nstr[size-i+1]) + 1;
            break;
        }
    }
#ifdef DEBUG
    printf("%llu\n", res);
#endif
    return res;
}

int is_count(char *nstr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(nstr[i] == '4' || nstr[i] == '9') return 1;
    }
    return 0;
}


int main(void) {
    char a1[BUF_SIZE/2];
    char a2[BUF_SIZE/2];
    get_str2(a1, a2, BUF_SIZE);
    int len1 = strlen(a1);
    int len2 = strlen(a2);
    uint64_t res = 0;
    init_digit_dp();
    res += count_number(a2, len2);
    res -= (count_number(a1, len1) - is_count(a1, len1));
    printf("%llu\n", res);
    return 0;
}
