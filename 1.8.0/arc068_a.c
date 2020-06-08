#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
  int64_t num;
  scanf("%lld", &num);
  return num;
}

int main(void) {
    int64_t num = get_int();
    int64_t cnt = num/11;
    cnt *= 2;
    if(num%11 > 6) {
        cnt += 2;
    } else if(num%11>0) {
        cnt++;
    }
    printf("%lld\n", cnt);
    return 0;
}
