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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}
#define NUM_MAX 16
#define PAT_MAX (1<<NUM_MAX)

int64_t calc_combi(int n, int k) {
    int64_t ans = 1;
    int i;
    while(k--) {
        ans *= n;
        n--;
    }
    return ans;
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);
    static int64_t dp[PAT_MAX];

    static char mat[NUM_MAX][NUM_MAX];
    static char outdeg[NUM_MAX];
    static char is_isolate[NUM_MAX];
    int i;
    for(i = 0; i < vs; i++) is_isolate[i] = 1;
    for(i = 0; i < es; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        mat[v1][v2] = 1;
        outdeg[v2]++;
        is_isolate[v1] = is_isolate[v2] = 0;
    }

    int iso_cnt = 0;
    int mask = 0;
    for(i = 0; i < vs; i++) {
        if(is_isolate[i]) iso_cnt++;
        else {
            mask |= (1<<i);
        }
    }
#ifdef DEBUG
    printf("iso_cnt: %d\n", iso_cnt);
#endif

    int pat, bit, pbit;
    for(i = 0; i < vs; i++) {
        if(outdeg[i]) continue;
        dp[(1<<i)] = 1;
    }

    for(pat = 1; pat < (1<<vs); pat++) {
        int cnt = __builtin_popcount(pat);
        int flag = 0;
        for(bit = 0; bit < vs; bit++) {
            if((pat & (1<<bit)) && is_isolate[bit]) flag = 1;
        }
        if(flag) continue;
        if(cnt == 1) continue;
        for(bit = 0; bit < vs; bit++) {
            if(!(pat & (1<<bit))) continue;
            int prev_pat = pat & ~(1<<bit);
            int cnt = 0;
            for(pbit = 0; pbit < vs; pbit++) {
                if(!(prev_pat & (1<<pbit))) continue;
                cnt += mat[pbit][bit];
            }
#ifdef DEBUG
            printf("[%d] %d -> %d: +%lld\n", flag, prev_pat, pat, dp[prev_pat]);
#endif
            if(cnt == outdeg[bit]) dp[pat] += dp[prev_pat];
        }
    }

    int64_t ans = calc_combi(vs, iso_cnt) * dp[mask];

    printf("%lld\n", ans);
    return 0;
}
