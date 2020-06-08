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

int get_int2(int64_t *a1, int64_t *a2) {
  scanf("%lld %lld", a1, a2);
  return 0;
}


int main(void) {
    int num = get_int();
    int i;
    int64_t acur;
    int64_t bcur;
    get_int2(&acur, &bcur);
    for(i = 1; i < num; i++) {
        int64_t ma, mb;
        get_int2(&ma, &mb);
        int64_t aprop = (acur-1)/ma + 1;
        int64_t bprop = (bcur-1)/mb + 1;
        int64_t mult = max(aprop, bprop);
        // update
        acur = mult*ma;
        bcur = mult*mb;
#ifdef DEBUG
        printf("%lld %lld\n", acur, bcur);
#endif
    }
    printf("%lld\n", acur+bcur);
    return 0;
}
