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

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main(void) {
    int n, m;
    get_int2(&n, &m);
    if(n > m) swap(&n, &m);
    int64_t ans = 0;
    if(n == 1) {
        if(m == 1) {
            ans = 1;
        } else {
            ans = m - 2;
        }
    } else {
        ans = (int64_t)(n-2)*(m-2);
    }
    printf("%lld\n", ans);
    return 0;
}
