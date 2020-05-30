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

#define POWER2_MAX 32

int main(void) {
    int num = get_int();
    int sign = (num>=0) ? 1 : -1;
    int anum = abs(num);
    static int map[POWER2_MAX];
    int bit;
    for(bit = 0; bit < POWER2_MAX; bit++) {
        if(!(anum & (1<<bit))) continue;
        int bit_sign = (bit%2) ? -1 : 1;
        map[bit] = bit_sign * sign;
    }

    // carry
    int msb = 0;
    for(bit = 0; bit < POWER2_MAX; bit++) {
        if(map[bit]==-1) {
            map[bit] = 1;
            map[bit+1] += 1;
        } else if (map[bit]==2) {
            map[bit] = 0;
            map[bit+1] -= 1;
        } else if (map[bit] == -2) {
            map[bit] = 0;
            map[bit+1] += 1;
        }
        if(map[bit]==1) msb = bit;
    }

    for(bit = msb; bit >= 0; bit--) {
        putchar('0' + map[bit]);
    }
    putchar('\n');
    return 0;
}
