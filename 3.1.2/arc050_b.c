#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int64_t *a1, int64_t *a2) {
  scanf("%llu %llu", a1, a2);
  return 0;
}

#define FLOWERS_MAX (uint64_t)(1e+18)

int main(void) {
    int64_t reds, blues;
    get_int2(&reds, &blues);
    int64_t x, y;
    get_int2(&x, &y);

    // given ans
    int64_t low = -1;
    int64_t high = reds + blues + 1;

    while(low + 1 < high) {
        // mid = A + B
        int64_t mid = (low + high) / 2;
        int64_t tmp = reds - mid;
        int64_t alimit, blimit;
        if(tmp < 0) { goto finish;}
        alimit = tmp/(x-1);
        tmp = blues - mid;
        if(tmp < 0) { goto finish; }
        blimit = tmp/(y-1);
        // lower bound
        if(alimit + blimit >= mid) {
            low = mid;
        } else {
finish:
            high = mid;
        }
#ifdef DEBUG
        printf("%lld %lld\n", alimit, blimit);
#endif
    }
    printf("%lld\n", low);
    return 0;
}
