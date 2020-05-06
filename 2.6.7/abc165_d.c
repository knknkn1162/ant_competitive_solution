#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int64_t *a1, int64_t *a2, int64_t *a3) {
  return scanf("%lld %lld %lld", a1, a2, a3);
}

int main(void) {
    int64_t a, b, limit;
    get_int3(&a, &b, &limit);

    int64_t x = min(limit, b-1);
    int64_t ans = floor(a*x/b) - a * floor(x/b);
    printf("%lld\n", ans);
    return 0;
}
