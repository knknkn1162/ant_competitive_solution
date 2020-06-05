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

int main(void) {
    int num, m;
    get_int2(&num, &m);
    int ans = m * 1900 + (num-m)*100;

    // cnt
    while(m) {
        ans *= 2;
        m -= 1;
    }
    printf("%d\n", ans);
    return 0;
}
