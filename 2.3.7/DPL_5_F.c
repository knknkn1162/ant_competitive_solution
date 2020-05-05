#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20
#define DIVISOR 1000000007

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}
#define NUM_MAX 1000
#define K_MAX 1000

static uint64_t factorial[NUM_MAX+K_MAX+1];
static uint64_t inv_factorial[NUM_MAX+K_MAX+1];

struct pair {
    int x;
    int y;
};

struct pair gcdext(int a, int b) {
    if(a == 0) { return (struct pair){0, 1}; }
    struct pair p = gcdext(b%a, a);
    return (struct pair){p.y - (b/a)*p.x, p.x};
}

void prep_combi(int n) {
    // prep
    int i;
    factorial[0] = factorial[1] = 1;
    for(i = 2; i <= n; i++) {
        factorial[i] = (factorial[i-1] * i)%DIVISOR;
    }

    inv_factorial[0] = inv_factorial[1] = 1;
    for(i = 2; i <= n; i++) {
        struct pair p = gcdext(i, DIVISOR);
        int inv = (p.x + DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1]*inv)%DIVISOR;
    }
}

uint64_t calc_combi(int n, int k) {
    uint64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    return ans;
}

void init() {
    prep_combi(NUM_MAX+K_MAX);
}

int main(void) {
    int n, k;
    init();
    get_int2(&n, &k);
    uint64_t ans = 0;
    
    if(n >= k) ans = calc_combi(n-1, k-1);
    printf("%d\n", (int)ans);
    return 0;
}
