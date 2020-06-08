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

// <arr[0]> <arr[1]> .. <arr[size-1]>
#define NUM_MAX 100000
#define DIVISOR 1000000007
int fget_array(char *map, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int stairs;
        scanf("%d", &stairs);
        map[stairs] = 0;
    }
    return 0;
}

int main(void) {
    static int64_t dp[NUM_MAX+1];
    int num, s;
    get_int2(&num, &s);
    static char map[NUM_MAX+1];
    memset(map, 0x01, NUM_MAX+1);
    fget_array(map, s);

    int i;
    dp[0] = 1;
    for(i = 1; i <= num; i++) {
        if(!map[i]) continue;
        dp[i] += dp[i-1];
        if(i>=2) dp[i] = (dp[i] + dp[i-2])%DIVISOR;
    }
    printf("%d\n", (int)dp[num]);
    return 0;
}
