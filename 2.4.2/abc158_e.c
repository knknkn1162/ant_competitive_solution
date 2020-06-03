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


int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define NUM_MAX 200000
#define BUF_SIZE (NUM_MAX+50)
#define PRIME_MAX 10000

int chr_to_digit(char ch) {
    return ch - '0';
}

int main(void) {
    int num, divisor;
    get_int2(&num, &divisor);

    static char str[BUF_SIZE];
    static int mod_map[PRIME_MAX];
    get_str(str, BUF_SIZE);
    int i;

    int64_t ans = 0;
    if(divisor == 2 || divisor == 5) {
        for(i = num-1; i >= 0; i--) {
            if(!(chr_to_digit(str[i])%divisor)) {
                ans += (i+1);
            }
        }
        goto finish;
    }
    
    // divisor has nothing to do with 10**n.
    int sum = 0;
    int power10 = 1;
    for(i = num-1; i >= 0; i--) {
        sum = (chr_to_digit(str[i])*power10+sum)%divisor;
        power10 = (power10*10)%divisor;
        mod_map[sum]++;
    }
    int offset = 0;
    ans += mod_map[offset];
#ifdef DEBUG
    printf("ans: %lld\n", ans);
#endif
    power10 = 1;
    for(i = num-1; i >= 0; i--) {
        offset = (chr_to_digit(str[i])*power10+offset)%divisor;
        power10 = (power10*10)%divisor;
        mod_map[offset]--;
        ans += mod_map[offset];
#ifdef DEBUG
        printf("ans: %d\n", mod_map[offset]);
#endif
    }
finish:
    printf("%lld\n", ans);
    return 0;
}
