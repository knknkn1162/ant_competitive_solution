#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
  int64_t num;
  scanf("%lld", &num);
  return num;
}

int get_int2(int *a1, int *a2) {
  scanf("%d.%d", a1, a2);
  return 0;
}

int main(void) {
    int64_t num = get_int();
    int i, f;
    get_int2(&i, &f);
    int64_t ans = num * ((i*100)+f);
    printf("%lld\n", ans/100);
}
