#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

#define NORMAL_FORMAT "%d is normal.\n"
#define CARMICHAEL_FORMAT "The number %d is a Carmichael number.\n"
#define POWER_MAX 17
#define SET_MAX 60000
struct pair {
    int ans;
    int input;
};

int main(void) {
    static struct pair ans[SET_MAX];
    int aidx = 0;
    /* is prime */
    while(1) {
        int num = get_int();
        if(!num) break;
        int divisor = num;
        int num_2 = sqrt(0.5 + num);
        int i;
        int flag = 0;
        if(num == 2 || num == 3) { goto finish; }
        for(i = 2; i <= num_2; i++) {
            if(!(num%i)) { flag = 1; break; }
        }
        /* if prime */
        if(!flag) {
            goto finish;
        }

        int base, p, bit;
        static uint64_t power[POWER_MAX+1];
        for(base = 2; base < num; base++) {
            memset(power, 0, sizeof(uint64_t)*(POWER_MAX+1));
            power[0] = base;
            for(p = 1; p <= POWER_MAX; p++) {
                power[p] = (power[p-1]*power[p-1])%divisor;
            }

            uint64_t res = 1;
            for(bit = 0; bit <= POWER_MAX; bit++) {
                if(!(num & (1<<bit))) continue;
                res = (res * power[bit])%divisor;
            }
            if(res != base) { flag = 0; break; }
        }
    finish:
        ans[aidx++] = (struct pair){flag, num};
    }
    int i;
    for(i = 0; i < aidx; i++) {
        printf(ans[i].ans ? CARMICHAEL_FORMAT : NORMAL_FORMAT, ans[i].input);
    }
    printf("\n");
    return 0;
}
