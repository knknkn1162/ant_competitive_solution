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

int get_int2(int *a1, int64_t *a2) {
  scanf("%d %lld", a1, a2);
  return 0;
}

#define NUM_MAX 50

int main(void) {
    int layers;
    int64_t cnt;
    get_int2(&layers, &cnt);

    static int64_t patties[NUM_MAX+1];
    static int64_t total[NUM_MAX+1];
    patties[0] = 1;
    total[0] = 1;
    int i;
    for(i = 1; i <= layers; i++) {
        patties[i] = patties[i-1]*2 + 1;
        total[i] = total[i-1]*2 + 3;
    }

    int64_t ans = 0;
    for(i = layers; i >= 0; i--) {
        if(cnt == 0) break;
        int64_t half = total[i]/2;
        // top half
        if(cnt > half) {
            ans += patties[i-1]+1;
            cnt -= half;
        // bottom half
        } else {
            if(i == 0) ans += 1;
        }
        cnt -= 1;
#ifdef DEBUG
        printf("%d: %lld, ans: %lld\n", i, cnt,  ans);
#endif
    }
    printf("%lld\n", ans);
    return 0;
}
