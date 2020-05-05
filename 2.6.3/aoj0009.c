#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 10
#define NUM_MAX 1000000
#define DIVISOR 1000000007

int main(void) {
    int i, j;
    static char is_prime[NUM_MAX];
    memset(is_prime, 0x01, NUM_MAX);
    is_prime[0] = is_prime[1] = 0;
    for(i = 2; i <= NUM_MAX; i++) {
        int limit = NUM_MAX/i;
        if(!is_prime[i]) continue;
        for(j = 2; j <= limit; j++) {
            is_prime[i*j] = 0;
        }
    }
    static int cum[NUM_MAX+1];
    for(i = 1; i <= NUM_MAX; i++) {
        cum[i] = cum[i-1] + is_prime[i];
    }
    while(1) {
        int num = 0;
        if(!scanf("%d", &num)) break;
        if(!num) break;
        printf("%d\n", cum[num]);
    }
    return 0;
}
