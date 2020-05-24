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

enum {
    ENUM_A,
    ENUM_C,
    ENUM_G,
    ENUM_T,
    ENUM_ALL,
};

#define SIZE 3
int blacklist[][SIZE] = {
    {ENUM_A, ENUM_G, ENUM_C},
    {ENUM_G, ENUM_A, ENUM_C},
    {ENUM_A, ENUM_C, ENUM_G},
};
int check(int *arr, int mask) {
    int i, j;
    int ans = 1;
    for(i = 0; i < sizeof(blacklist)/sizeof(blacklist[0]); i++) {
        if(!((1<<i) & mask)) continue;
        int flag = 1;
        for(j = 0; j < SIZE; j++) {
            if(arr[j] != blacklist[i][j]) { flag = 0; break; }
        }
        if(flag) ans = 0;
    }
    return ans;
}

#define NUM_MAX 100
#define DIVISOR ((int64_t)(1e+9)+7)

int main(void) {
    int num = get_int();
    static int64_t dp[NUM_MAX+1][ENUM_ALL][ENUM_ALL][ENUM_ALL][ENUM_ALL];
    int n;
    int i, j, k, l;
    // for n==3
    for(i = 0; i < ENUM_ALL; i++) {
        for(j = 0; j < ENUM_ALL; j++) {
            for(k = 0; k < ENUM_ALL; k++) {
                int idx[3] = {i, j, k};
                if(check(idx, (1<<3)-1)) dp[3][ENUM_T][i][j][k] = 1;
            }
        }
    }

    int prev;
    for(n = 4; n <= num; n++) {
        for(i = 0; i < ENUM_ALL; i++) {
            for(j = 0; j < ENUM_ALL; j++) {
                for(k = 0; k < ENUM_ALL; k++) {
                    for(l = 0; l < ENUM_ALL; l++) {
                        int idx[SIZE] = {j, k, l};
                        int idx2[SIZE] = {i, k, l};
                        int idx3[SIZE] = {i, j, l};
                        int flag = 1;
                        flag &= check(idx, (1<<3)-1);
                        flag &= check(idx2, 1);
                        flag &= check(idx3, 1);
                        int64_t res = 0;
                        if(!flag) continue;
                        for(prev = 0; prev < ENUM_ALL; prev++) {
                            res = (dp[n-1][prev][i][j][k]+res)%DIVISOR;
                        }
                        dp[n][i][j][k][l] = res;
                    }
                }
            }
        }
    }
    int64_t ans = 0;
    for(i = 0; i < ENUM_ALL; i++) {
        for(j = 0; j < ENUM_ALL; j++) {
            for(k = 0; k < ENUM_ALL; k++) {
                for(l = 0; l < ENUM_ALL; l++) {
                    ans = (ans + dp[num][i][j][k][l])%DIVISOR;
                }
            }
        }
    }
    printf("%d\n", (int)ans);
    return 0;
}
