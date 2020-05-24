#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int64_t *a1, int64_t *a2) {
  scanf("%lld %lld", a1, a2);
  return 0;
}

#define BIT_MAX 40
int64_t func(int64_t num) {
    int bit;
    int64_t power = 1;
    int64_t ans = (num/2)%2;
    for(bit = 1; bit <= BIT_MAX; bit++) {
        // update
        power *= 2;
        int64_t order = num % (power*2);
        if(order <= power) continue; // if 0
        if(order%2) ans |= power; // if order=odd
    }
    return ans;
}

int main(void) {
    int64_t start, end;
    get_int2(&start, &end);
    // func([0, end+1)) - func([0, start))
    int64_t ans = func(end+1);
    ans = (ans ^ func(start));
    printf("%lld\n", ans);

    return 0;
}
