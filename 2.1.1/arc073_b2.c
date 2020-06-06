#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

#define NUM_MAX 100

struct prod {
    int weight;
    int value;
};

int desc(const void *a1, const void *a2) {
    return *(int*)a2 - *(int*)a1;
}

#define RANGE_MAX 3
int main(void) {
    int num, ulimit;
    get_int2(&num, &ulimit);
    static struct prod prods[NUM_MAX];
    int i, j;
    for(i = 0; i < num; i++) {
        get_int2(&prods[i].weight, &prods[i].value);
    }
    int base = prods[0].weight;
    static int map[RANGE_MAX+1];
    static int cum[RANGE_MAX+1][NUM_MAX+1];
    static int vidx[RANGE_MAX+1];
    for(i = 0; i < RANGE_MAX+1; i++) vidx[i] = 1;

    for(i = 0; i < num; i++) {
        int idx = prods[i].weight-base;
        map[idx]++;
        cum[idx][vidx[idx]++] = prods[i].value;
    }

    for(i = 0; i <= RANGE_MAX; i++) {
        qsort(&cum[i][1], vidx[i], sizeof(int), desc);
        for(j = 1; j <= NUM_MAX; j++) {
            cum[i][j] += cum[i][j-1];
        }
    }

    int k0, k1, k2, k3;
    int cnt_max = ulimit/base;
    int ans = 0;
#ifdef DEBUG
    printf("cnt_max: %d\n", cnt_max);
    for(i = 0; i < RANGE_MAX+1; i++) printf(" %d", vidx[i]-1);
    putchar('\n');
#endif
    for(k0 = 0; k0 < vidx[0]; k0++) {
        for(k1 = 0; k1 < vidx[1]; k1++) {
            for(k2 = 0; k2 < vidx[2]; k2++) {
                for(k3 = 0; k3 < vidx[3]; k3++) {
                    int ks[RANGE_MAX+1] = {k0, k1, k2, k3};
                    // 1-indexed -> 0-indexed
                    int cnt_sum = 0;
                    for(i = 0; i < RANGE_MAX+1; i++) cnt_sum += ks[i];
                    if(cnt_sum > cnt_max) continue;
                    int w = cnt_sum * base;
                    for(i = 0; i < RANGE_MAX+1; i++) {
                        w += ks[i]*i;
                    }
                    if(w > ulimit) break;
                    int res = 0;
                    for(i = 0; i < RANGE_MAX+1; i++) {
                        res += cum[i][ks[i]];
                    }
                    ans = max(ans, res);
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
