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

#define NUM_2_MAX 1000000

int main(void) {
    int64_t num = get_int();
    static char primen[NUM_2_MAX+1];
    memset(primen, 0x01, NUM_2_MAX+1);

    int i, j;
    for(i = 2; i <= NUM_2_MAX; i++) {
        if(!primen[i]) break;
        int ulimit = NUM_2_MAX/i;
        for(j = 2; j <= ulimit; j++) {
            primen[i*j] = 0;
        }
    }
    for(i = 2; i <= 1000; i++) {
        int n = i;
        if(!primen[n]) break;
        while(n<=NUM_2_MAX) {
            primen[n] = 1;
            n *= i;
        }
    }

    int ans = 0;
    int divisor = 2;
    while(num >= divisor) {
        // num is prime
        if(divisor > NUM_2_MAX) {
            ans++;
            break;
        }
        if(!primen[divisor]) { divisor++; continue; }
        if(num%divisor) { divisor++; continue; }
        num /= divisor;
        divisor++;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
