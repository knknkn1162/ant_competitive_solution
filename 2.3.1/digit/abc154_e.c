#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define DIGIT_MAX 100
#define K_MAX 3
#define BUF_SIZE (DIGIT_MAX+10)

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

int main(void) {
    char nstr[BUF_SIZE];
    get_str(nstr, BUF_SIZE);
    int len = strlen(nstr)-1;
    int count = get_int();
    static uint64_t dp[DIGIT_MAX+1][10][K_MAX+1];
    static uint64_t map[K_MAX+1];

    // dp[1]
    int i;
    for(i = 0; i <= 9; i++) {
        dp[1][i][i!=0] = 1;
    }

    int d, k;
    for(d = 2; d <=len; d++) {
        memset(map, 0, sizeof(uint64_t)*(K_MAX+1));
        for(i = 0; i <= 9; i++) {
            for(k = 0; k <= count; k++) {
                map[k] += dp[d-1][i][k];
            }
        }
#ifdef DEBUG
        for(k = 0; k <= count; k++) {
            printf("%llu ", map[k]);
        }
        putchar('\n');
#endif
        for(i = 0; i <= 9; i++) {
            for(k = 0; k <= count; k++) {
                if(!i) {
                    dp[d][i][k] = map[k];
                } else {
                    if(k>=1) dp[d][i][k] = map[k-1];
                }
            }
        }
    }

    uint64_t res = 0;
    int c = count;
    for(d = len; d >= 1; d--) {
        int ch = nstr[len-d] - '0';
        for(i = 0; i < ch; i++) {
            res += dp[d][i][c];
        }
        if(ch!=0) c--;
#ifdef DEBUG
        printf("[%d] -> count: %d, %llu\n",ch, c, res);
#endif
        // all numbers are 0 below $d digit
        if(c==0) { res++; break; }
    }
    printf("%llu\n", res);
    return 0;
}
