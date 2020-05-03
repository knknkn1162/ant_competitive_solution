#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 10000
#define RESTS_MAX 1000
#define BUF_SIZE (NUM_MAX*6+50)

int get_int4(int *a1, int *a2, int *a3, int *a4) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d %d", a1, a2, a3, a4);
#else
#error
#endif
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

int main(void) {
    int ts, rests, goal, limit;
    static int tanks[NUM_MAX];
    static int dp[NUM_MAX+1][RESTS_MAX];
    memset(dp, 0x01, sizeof(int)*(NUM_MAX+1)*RESTS_MAX);
    // dp[none][start] = 0
    dp[0][0] = 1;
    get_int4(&ts, &rests, &goal, &limit);
    fget_array(tanks, ts);
    int i;
    int cur;
    for(i = 1; i <= ts; i++) {
        int t = tanks[i-1];
        // min
        for(cur = 0; cur < rests; cur++) {
            dp[i][cur] = dp[i-1][cur];
            int diff = cur - t;
            int prev, rounds;
            if(diff>=0) {
                prev = diff;
                rounds = 0;
            } else {
                prev = (rests - abs(diff%rests))%rests;
                rounds = (abs(diff)-1)/rests + 1;
            }
#ifdef DEBUG
            printf("[%d] %d +%d rounds: %d->%d\n", i, dp[i-1][prev], rounds, prev, cur);
#endif
            dp[i][cur] = min(dp[i][cur], dp[i-1][prev] + rounds);
        }
    }
#ifdef DEBUG
    printf("ans: %d\n", dp[ts][goal]);
#endif
    printf("%s\n", dp[ts][goal] <= limit ? "Yes" : "No");
    return 0;
}
