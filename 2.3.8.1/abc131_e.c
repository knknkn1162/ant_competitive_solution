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

#define NUM_MAX 2000
#define DIVISOR 1000000007

struct pair {
    int x;
    int y;
};

struct pair gcdext(int a, int b) {
    if(a==0) { return (struct pair){0, 1}; }
    struct pair p = gcdext(b%a, a);
    return (struct pair){p.y - (b/a)*p.x, p.x};
}
static int64_t factorial[NUM_MAX+2];
static int64_t inv_factorial[NUM_MAX+2];

void init_combi(int size) {
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    int i;
    for(i = 2; i <= size; i++) {
        factorial[i] = (factorial[i-1] * i)%DIVISOR;
        struct pair p = gcdext(i, DIVISOR);
        int inv = (p.x + DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1] * inv)%DIVISOR;
    }
    return;
}

int64_t calc_combi(int n, int k) {
    if(k > n) return 0;
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    return ans;
}

int main(void) {
    int num, blues;
    get_int2(&num, &blues);
    int reds = num - blues;

    init_combi(num+1);

    int i;
    for(i = 1; i <= blues; i++) {
        int64_t ans = 1;
        ans = (ans * calc_combi(reds+1, i))%DIVISOR;
        ans = (ans * calc_combi(blues-1, i-1))%DIVISOR;
        printf("%d\n", (int)ans);
    }
    return 0;
}
