#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 100
// 2**10 >= 10*3
#define POWER2_MAX 60
#define POWER3_MAX 40
#define POWER5_MAX 30
#define BUF_SIZE 30

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

int get_int2(int *a1, uint64_t *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %llu", a1, a2);
#else
#error
#endif
  return 0;
}

int table[6][3] = {
    {0,0,0}, // 1
    {1,0,0}, // 2
    {0,1,0}, // 3
    {2,0,0}, // 4
    {0,0,1}, // 5
    {1,1,0}, // 6
};

int main(void) {
    int num;
    uint64_t divisor;
    get_int2(&num, &divisor);
    static int map[7];
    int prime = 2;
    int flag = 1;
    while(divisor>1) {
        if(prime>=7) { flag = 0; break; }
        if(divisor%prime) {
            prime++;
            continue;
        }
        map[prime]++;
        divisor /= prime;
    }
    if(!flag) { printf("0\n"); return 0; }
    int i;
#ifdef DEBUG
    for(i = 1; i <= 6; i++) {
        printf("%d ", map[i]);
    }
    putchar('\n');
#endif
    static long double dp[NUM_MAX+1][POWER2_MAX+1][POWER3_MAX+1][POWER5_MAX+1];
    int k1, k2, k3, j;
    dp[0][0][0][0] = 1;
    for(i = 1; i <= num; i++) {
        for(k1 = 0; k1 <= map[2]; k1++) {
            for(k2 = 0; k2 <= map[3]; k2++) {
                for(k3 = 0; k3 <= map[5]; k3++) {
                    for(j = 0; j < 6; j++) {
                        int diff1 = table[j][0];
                        int diff2 = table[j][1];
                        int diff3 = table[j][2];
                        dp[i][min(map[2], k1+diff1)][min(map[3], k2+diff2)][min(map[5], k3+diff3)] += dp[i-1][k1][k2][k3]/6;
                    }
                }
            }
        }
    }
    printf("%.8Lf\n", dp[num][map[2]][map[3]][map[5]]);
    return 0;
}
