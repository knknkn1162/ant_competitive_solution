#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int3(int64_t *a1, int64_t *a2, int64_t *a3) {
  scanf("%lld %lld %lld", a1, a2, a3);
  return 0;
}

int main(void) {
    int64_t a, b, c;
    get_int3(&a, &b, &c);
    // a + 2*sqrt(a*b) + b < c
    // 2*sqrt(a*b) < c-a-b
    int64_t right = c-a-b;
    int flag;
    if(right<=0) {
        flag = 0;
    } else {
        flag = (right*right-a*b*4)>0;
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}
