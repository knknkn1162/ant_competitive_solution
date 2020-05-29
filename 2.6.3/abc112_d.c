#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

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

#define NUM_MAX 100000
// sqrt(1e+9)
#define M_2_MAX 31623

int main(void) {
    int num, sum;
    get_int2(&num, &sum);
    int num_2 = sqrt(0.5+sum);

    int div;
    int ans;
    for(div = 1; div <= num_2; div++) {
        if(sum%div) { continue; }
        int large = sum / div;
        if(div >= num) {ans = large; break;}
        if(sum / div >= num) ans = div;
    }
    printf("%d\n", ans);
    return 0;
}
