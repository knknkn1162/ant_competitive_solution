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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 300000
#define POWER_MAX 60

#define power2(bit) (1LL<<bit)
#define DIVISOR 1000000007

int main(void) {
    int num = get_int();
    static int64_t arr[NUM_MAX];
    static int cum[NUM_MAX+1][POWER_MAX+1];
    fget_array(arr, num);

    int i, bit;
    for(i = num-1; i >= 0; i--) {
        for(bit = 0; bit <= POWER_MAX; bit++) {
            if(!(arr[i] & power2(bit))) continue;
            cum[i][bit]++;
        }
        // cumulative
        for(bit = 0; bit <= POWER_MAX; bit++) {
            cum[i][bit] += cum[i+1][bit];
        }
#ifdef DEBUG
        for(bit = 0; bit <= POWER_MAX; bit++) {
            printf(" %d", cum[i][bit]);
        }
        putchar('\n');
#endif
    }

    static int64_t bit_sum[POWER_MAX+1];
    for(i = 0; i < num-1; i++) {
        for(bit = 0; bit <= POWER_MAX; bit++) {
            if(!(arr[i] & power2(bit))) {
                bit_sum[bit] += cum[i+1][bit];
            } else {
                bit_sum[bit] += ((num-i-1) - cum[i+1][bit]);
            }
            // it's necessary to do DIVISOR
            bit_sum[bit] = bit_sum[bit]%DIVISOR;
        }
    }
    int64_t ans = 0;
    int64_t power2 = 1;
    for(i = 0; i <= POWER_MAX; i++) {
        ans = (ans + power2 * bit_sum[i])%DIVISOR;
        power2 = (power2 * 2) % DIVISOR;
    }
    printf("%d\n", (int)ans);
    return 0;
}
