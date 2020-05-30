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
#define NUM_MAX 200000
#define DIVISOR 1000000007

static int64_t factorial[NUM_MAX+1];
static int64_t inv_factorial[NUM_MAX+1];

struct pair {
    int x;
    int y;
};

struct pair gcdext(int a, int b) {
    if(a==0) { return (struct pair){0, 1}; }
    struct pair p = gcdext(b%a, a);
    return (struct pair){ p.y - (b/a)*p.x, p.x };
}

void init_combi(void) {
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    int i;
    for(i = 2; i <= NUM_MAX; i++) {
        factorial[i] = (factorial[i-1]*i)%DIVISOR;
        struct pair p = gcdext(i, DIVISOR);
        int inv = (p.x+DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1]*inv)%DIVISOR;
    }
    return;
}

int64_t get_combi(int n, int k) {
    int64_t res = 1;
    res = (res * factorial[n])%DIVISOR;
    res = (res * inv_factorial[n-k])%DIVISOR;
    res = (res * inv_factorial[k])%DIVISOR;
    return res;
}

int64_t get_homo(int n, int k) {
    return get_combi(n+k-1, k);
}

int main(void) {
    int num, k;
    get_int2(&num, &k);
    if(k >= num-1) k = num-1;
    init_combi();

    int i;
    int64_t ans = 0;
    for(i = 0; i <= k; i++) {
        int64_t res = 1;
        // i: # of zero
        res = (res * get_combi(num, i))%DIVISOR;
        res = (res * get_homo(num-i, i))%DIVISOR;
        ans = (res + ans)%DIVISOR;
    }
    printf("%d\n", (int)ans);
    return 0;
}
