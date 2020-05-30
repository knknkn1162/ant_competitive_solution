#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}
#define NUM_MAX 200000
#define COLOR_MAX 200000
#define DIVISOR 998244353

static int64_t factorial[NUM_MAX*2];
static int64_t inv_factorial[NUM_MAX*2];
static int64_t power_of_c[NUM_MAX+1];

struct pair {
    int x;
    int y;
};

struct pair gcdext(int a, int b) {
    if(a==0) { return (struct pair){0, 1}; }
    struct pair p = gcdext(b%a, a);
    return (struct pair){ p.y - (b/a)*p.x , p.x };
}

void init(int colors) {
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    int i;
    for(i = 2; i < NUM_MAX*2; i++) {
        factorial[i] = (factorial[i-1]*i)%DIVISOR;
        struct pair p = gcdext(i, DIVISOR);
        int inv = (p.x+DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1]*inv)%DIVISOR;
    }
    power_of_c[0] = 1;
    for(i = 1; i <= NUM_MAX; i++) {
        power_of_c[i] = (power_of_c[i-1] * (colors-1))%DIVISOR;
    }
    return;
}

int64_t calc_combi(int n, int k) {
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    return ans;
}

int main(void) {
    int num, colors, tlimit;
    get_int3(&num, &colors, &tlimit);
    int64_t ans = 0;
    init(colors);

    int k;
    for(k = 0; k <= tlimit; k++) {
        int64_t res = colors;
        int types = num-k;
        res = ( res * power_of_c[types-1] )%DIVISOR;
        res = (res * calc_combi(num-1, num-types))%DIVISOR;
#ifdef DEBUG
        printf("%d -> %lld\n", k, res);
#endif
        ans = (ans + res)%DIVISOR;
    }

    printf("%d\n", (int)ans);
    return 0;
}
