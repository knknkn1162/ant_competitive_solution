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
#define ULIMIT 55555
#define NUM_MAX (ULIMIT*5)
#define SET_MAX 55

static int map[5][ULIMIT];
static int idx[5];

void push(int val) {
    int mod = val%5;
    map[mod][idx[mod]++] = val;
}

int main(void) {
    int num = get_int();
    static char prime[NUM_MAX];
    memset(prime, 0x01, NUM_MAX);
    // sieve
    int i, j;
    for(i = 2; i <= ULIMIT; i++) {
        int ulimit = ULIMIT/i;
        if(!prime[i]) continue;
        for(j = 2; j <= ulimit; j++) {
            prime[i*j] = 0;
        }
    }

    for(i = 2; i <= ULIMIT; i++) {
        if(!prime[i]) continue;
        push(i);
    }

    int argmax = 0;
    int cnt_max = 0;
    for(i = 0; i < 5; i++) {
        if(cnt_max < idx[i]) {
            argmax = i;
            cnt_max = idx[i];
        }
    }
#ifdef DEBUG
    printf("%d argmax: %d\n", cnt_max, argmax);
#endif
    for(i = 0; i < num; i++) {
        printf("%d\n", map[argmax][i]);
    }
    return 0;
}
