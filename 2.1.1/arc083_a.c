#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

#define SUM_MAX 3000

struct pair {
    int whole;
    int sugar;
};

int main(void) {
    int wa, wb;
    get_int2(&wa, &wb);
    int sa, sb;
    get_int2(&sa, &sb);
    int ulimit, sum;
    get_int2(&ulimit, &sum);

    static char water_cand[31];
    water_cand[0] = 1;
    int i, j;
    for(i = 0; i <= 30; i++) {
        for(j = 0; j <= 30; j++) {
            int w = wa*i+wb*j;
            if(w*100 > sum) continue;
            water_cand[w] = 1;
        }
    }
    static char sugar_cand[3001];
    for(i = 0; i <= 3000; i++) {
        for(j = 0; j <= 3000; j++) {
            int s = sa*i+sb*j;
            if(s > sum) break;
            sugar_cand[s] = 1;
        }
    }

    int w, s;
    struct pair sol = {wa*100, 0};
    double density = 0;
    for(w = 1; w <= 30; w++) {
        if(!water_cand[w]) continue;;
        for(s = 1; s <= sum; s++) {
            if(!sugar_cand[s]) continue;
            int whole = w*100+s;
            // too much sugar
            if(s > ulimit*w) break;
            if(whole > sum) break;
            double d = (double)s*100/whole;
#ifdef DEBUG
            printf("water: %d, salt: %d -> %lf\n", w*100, s,d);
#endif
            // update
            if(d > density) {
                sol = (struct pair){.whole=whole, .sugar=s};
                density = d;
            }
        }
    }

    printf("%d %d\n", sol.whole, sol.sugar);
    return 0;
}
