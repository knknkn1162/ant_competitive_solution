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
    int num, k;
    get_int2(&num, &k);
    int64_t cnt = 1; // (k,k,k)
    cnt += 3*(num-1); // (*,k,k)
    int64_t tmp = 6*(k-1);
    tmp *= (num-k); // (*,k,*)
    cnt += tmp;
#ifdef DEBUG
    printf("%d\n", cnt);
#endif

    double ans = cnt;
    int i;
    for(i = 0; i < 3; i++) {
        ans /= num;
    }
    printf("%.10lf\n", ans);
    return 0;
}
