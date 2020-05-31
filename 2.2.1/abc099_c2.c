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

int main(void) {
    int ulimit = get_int();
    static int dp[NUM_MAX+1];
    int i;
    int units[UNIT_MAX];
    int uidx = 0;
    int unit = 6;
    while(ulimit >= unit) {
        units[uidx++] = unit;
        unit *= 6;
    }
    unit = 9;
    while(ulimit >= unit) {
        units[uidx++] = unit;
        unit *= 9;
    }
    int k;
    for(i = 0; i <= ulimit; i++) dp[i] = i;
    for(k = 0; k < uidx; k++) {
        int unit = units[k];
        for(i = 0; i <= ulimit-unit; i++) {
            dp[i+unit] = min(dp[i+unit], dp[i]+1);
        }
    }
    printf("%d\n", dp[ulimit]);
    return 0;
}
