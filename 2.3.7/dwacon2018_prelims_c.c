#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

#define NUM_MAX 100
#define SUM_MAX 1000
#define DIVISOR 1000000007
#define BUF_SIZE (NUM_MAX*5+50)

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

static int split_dp[NUM_MAX+1][SUM_MAX+1];

void prep_splits(int sum, int num) {
    split_dp[0][0] = 1;
    int n, s;
    for(n = 1; n <= num; n++) {
        uint64_t res;
        for(s = 0; s <= sum; s++) {
            res = split_dp[n-1][s];
            if(s>=n) res = (res + split_dp[n][s-n])%DIVISOR;
            split_dp[n][s] = res;
        }
    }
    return;
}

uint64_t calc_cases(int sum, int* arr, int size) {
    static int cnt[SUM_MAX+1];
    static uint64_t dp[NUM_MAX+1][SUM_MAX+1];
    memset(cnt, 0, sizeof(int)*(SUM_MAX+1));
    memset(dp, 0, sizeof(uint64_t)*(NUM_MAX+1)*(SUM_MAX+1));
    int i;
    for(i = 0; i < size; i++) {
        cnt[arr[i]]++;
    }

    dp[0][0] = 1;
    int s, j;
    int cur = 1;
    for(i = SUM_MAX; i >= 0; i--) {
        if(!cnt[i]) continue;
        int n = cnt[i]; // splits
        for(s = 0; s <= sum; s++) {
            uint64_t res = 0;
            for(j = 0; j <= s; j++) {
#ifdef DEBUG
                printf("%d: %d * %d\n", j, dp[cur-1][j], split_dp[n][s-j]);
#endif
                res = (res + dp[cur-1][j] * split_dp[n][s-j])%DIVISOR;
            }
            dp[cur][s] = res;
        }
        cur++;
    }
#ifdef DEBUG
    printf("ans: %d\n", (int)dp[cur-1][sum]);
#endif
    return dp[cur-1][sum];
}

int main(void) {
    int anum, bnum;
    int asum = 0;
    int bsum = 0;
    int i;
    int arr[NUM_MAX];
    int brr[NUM_MAX];
    get_int2(&anum, &bnum);
    fget_array(arr, anum);
    fget_array(brr, bnum);
    for(i = 0; i < anum; i++) asum += arr[i];
    for(i = 0; i < bnum; i++) bsum += brr[i];

    prep_splits(max(asum, bsum), max(anum, bnum));

    // calc A's pattern according to brr
    uint64_t res = 1;
    res = (res * calc_cases(bsum, arr, anum))%DIVISOR;
    res = (res * calc_cases(asum, brr, bnum))%DIVISOR;

    printf("%d\n", (int)res);
    return 0;
}
