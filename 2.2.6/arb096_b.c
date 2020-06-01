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

int64_t get_long(void) {
  int64_t num;
  scanf("%lld", &num);
  return num;
}

int get_int2(int64_t *a1, int *a2) {
  scanf("%lld %d", a1, a2);
  return 0;
}

// sort
int asc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return 1;
    if(aa1 == aa2) return 0;
    return -1;
}

#define NUM_MAX 100000



int main(void) {
    int num = get_int();
    int64_t circle = get_long();
    static int64_t pos[NUM_MAX+1];
    static int64_t value[NUM_MAX+1];

    int i;
    pos[0] = value[0] = 0;
    for(i = 1; i <= num; i++) {
        int64_t p;
        int val;
        get_int2(&p, &val);
        pos[i] = p;
        value[i] = val;
    }
    int64_t ans = 0;

    static int64_t rdp[NUM_MAX+2];
    int64_t prev = 0;
    int64_t profit = 0;
    for(i = num; i >= 0; i--) {
        int64_t cur = circle - pos[i];
        profit = profit -(cur-prev) + value[i];
        rdp[i] = max(rdp[i+1], profit - cur);
        prev = cur;
    }

    // cw
    prev = 0;
    profit = 0;
    static int64_t dp[NUM_MAX+2];
    for(i = 1; i <= num; i++) {
        int64_t cur = pos[i];
        profit = profit - (cur-prev) + value[i];
        dp[i] = max(dp[i-1], profit - cur);
#ifdef DEBUG
        printf("[<-%lld] %lld %lld\n", cur, profit, rdp[i]);
#endif
        ans = max(ans, profit + rdp[i+1]);
        prev = cur;
    }

    prev = 0;
    profit = 0;
    for(i = num; i >= 1; i--) {
        int64_t cur = circle - pos[i];
        profit = profit - (cur-prev)+value[i];
#ifdef DEBUG
        printf("[->%lld] %lld %lld\n", cur, profit, dp[i]);
#endif
        ans = max(ans, profit + dp[i-1]);
        prev = cur;
    }

    printf("%lld\n", ans);

    return 0;
}
