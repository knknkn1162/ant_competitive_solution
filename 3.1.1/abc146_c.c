#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 50
#define DIVISOR 1000000007

int get_int3(int *a1, int *a2, int64_t *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %lld", a1, a2, a3);
#else
#error
#endif
  return 0;
}

int get_digit(int64_t num) {
    int cnt = 0;
    while(num) {
        num = num/10;
        cnt++;
    }
    return cnt;
}

#define NUM_MAX ((int64_t)1e+9)

int main(void) {
    int a, b;
    int64_t limit;
    get_int3(&a, &b, &limit);

    int64_t low = -1;
    int64_t high = NUM_MAX + 1;

    while(low + 1 < high) {
        int64_t mid = (low + high)/2;
        int ds = get_digit(mid);
#ifdef DEBUG
        printf("%lld -> %d\n", mid, ds);
#endif
        int64_t cost = mid * a + (int64_t)ds * b;
        if(cost <= limit) {
            low = mid;
        } else {
            high = mid;
        }
    }

    printf("%lld\n", low == -1 ? 0 : low);
    return 0;
}
