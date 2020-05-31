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
#define UNIT_MAX 100
#define NUM_MAX 100000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int units[UNIT_MAX];
    int uidx = 0;
    int ulimit = get_int();

    int num = 6;
    while(ulimit >= num) {
        units[uidx++] = num;
        num *= 6;
    }
    num = 9;
    while(ulimit >= num) {
        units[uidx++] = num;
        num *= 9;
    }
    qsort(units, uidx, sizeof(int), asc);

    static int dp[NUM_MAX+1];
    int i;
    for(i = 0; i <= ulimit; i++) dp[i] = i;

    int k;
    for(k = 0; k < uidx; k++) {
        int unit = units[k];
        for(i = 0; i <= ulimit; i++) {
            if(i>=unit) dp[i] = min(dp[i], dp[i-unit]+1);
        }
    }
    printf("%d\n", dp[ulimit]);

    return 0;
}
