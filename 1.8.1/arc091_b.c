#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

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

int main(void) {
    int num, rem;
    get_int2(&num, &rem);
    int64_t ans = 0;
    if(rem==0) {
        ans = (int64_t)num*num;
        goto finish;
    }

    int b;
    for(b = rem+1; b <= num; b++) {
        // b+rem, b+rem+1, ...b+(b-1)
        int res = num/b;
        int re = num%b;
        int cnt = (re-rem+1);
        if(cnt <= 0) cnt = 0;
#ifdef DEBUG
        printf("%d: %d\n", b, res*(b-rem)+cnt);
#endif
        ans += (int64_t)res * (b-rem) + cnt;
    }
finish:
    printf("%lld\n", ans);
    return 0;
}
