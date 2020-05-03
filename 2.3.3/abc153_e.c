#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20

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

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

struct magic {
    int damage;
    int consume;
};

#define MAGICS_MAX 1000
#define HP_MAX 10000

int main(void) {
    int hp, num;
    static struct magic magics[MAGICS_MAX];
    static int dp[HP_MAX+1];
    memset(dp, 0x3f, sizeof(int)*(HP_MAX+1));
    dp[0] = 0;
    get_int2(&hp, &num);
    int i;
    for(i = 0; i < num; i++) {
        get_int2(&magics[i].damage, &magics[i].consume);
    }

    int h;
    for(i = 0; i < num; i++) {
        int d = magics[i].damage;
        int m = magics[i].consume;
        for(h = 1; h <= hp; h++) {
            dp[h] = min(dp[h], dp[max(0, h-d)] + m);
        }
#ifdef DEBUG
        printf("%d: %d\n", i, dp[hp]);
#endif
    }
    printf("%d\n", dp[hp]);
    return 0;
}
