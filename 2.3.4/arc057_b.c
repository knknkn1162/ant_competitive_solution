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

#define DAYS_MAX 2000

int main(void) {
    int days, wins;
    int i;
    get_int2(&days, &wins);
    int games[DAYS_MAX+1];
    int cum[DAYS_MAX+1];
    for(i = 1; i <= days; i++) {
        games[i] = get_int();
    }

    // cum: sum of games in 1st~i-th days
    for(i = 1; i <= days; i++) {
        cum[i] = cum[i-1] + games[i];
    }
    static uint64_t dp[DAYS_MAX+1][DAYS_MAX+1];
    memset(dp, 0x01, sizeof(uint64_t)*(DAYS_MAX+1)*(DAYS_MAX+1));
    dp[0][0] = 0;
    dp[1][0] = 0; dp[1][1] = 1;

    // find smallest wins
    int day, win;
    for(day = 2; day <= days; day++) {
        for(win = 1; win <= day; win++) {
            // in lose case
            dp[day][win] = min(dp[day][win], dp[day-1][win]);
            // in win case
            uint64_t min_wins = cum[day] * dp[day-1][win-1] / cum[day-1] + 1;
            printf("%d %d -> min: %llu\n", day, win, min_wins);
            dp[day][win] = min(dp[day][win], min_wins);
        }
    }
    int ans = 0;
    for(i = 1; i <= days; i++) {
#ifdef DEBUG
        printf("%d: %d\n", i, (int)dp[days][i]);
#endif
        if(dp[days][i] > (uint64_t)wins) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
