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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
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
    return (struct pair){p.y - (b/a)*p.x, p.x};
}

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
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    return ans;
}

int64_t calc_sum(int size) {
    int64_t ans = 0;
    int i;
    for(i = 1; i < size; i++) {
        int64_t res = 1;
        res = (res * i)%DIVISOR;
        res = (res * (size-i))%DIVISOR;
        ans = (ans + res)%DIVISOR;
    }
    return ans;
}

int main(void) {
    int row, col, k;
    get_int3(&row, &col, &k);
    init_combi(row*col);

    int64_t combi = calc_combi(row*col-2, k-2);
    int64_t xcnt = calc_sum(row);
    int64_t ycnt = calc_sum(col);
#ifdef DEBUG
    printf("%lld %lld: combi: %lld\n", xcnt, ycnt, combi);;
#endif
    xcnt = (xcnt * combi)%DIVISOR;
    xcnt = (xcnt * col * col)%DIVISOR;

    ycnt = (ycnt * combi)%DIVISOR;
    ycnt = (ycnt * row * row)%DIVISOR;

    int64_t ans = (xcnt + ycnt)%DIVISOR;
    printf("%d\n", (int)ans);
    return 0;
}
