#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int main(void) {
    int num, k;
    get_int2(&num, &k);
    int64_t ans = 0;
    int num_k = num/k;
    ans += (int64_t)num_k*num_k*num_k;
    if(!(k%2)) {
        int num_k = (num+k/2)/k;
        ans += (int64_t)num_k*num_k*num_k;
    }
    printf("%lld\n", ans);
    return 0;
}
