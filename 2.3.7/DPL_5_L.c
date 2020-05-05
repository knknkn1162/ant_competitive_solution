#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20
#define DIVISOR 1000000007

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

#define NUM_MAX 1000
#define K_MAX 1000

// pdp[# of partitions][# of balls]
static uint64_t pdp[K_MAX+1][NUM_MAX+1];
void init() {
    pdp[0][0] = 1;
    int i, j;
    for(i = 1; i <= K_MAX; i++) {
        for(j = 0; j <= NUM_MAX; j++) {
            pdp[i][j] = pdp[i-1][j];
            if(j>=i) pdp[i][j] = (pdp[i][j] + pdp[i][j-i])%DIVISOR;
        }
    }
    return;
}

int main(void) {
    int n, k;
    get_int2(&n, &k);
    init();
    uint64_t ans = (n-k>=0) ? (int)pdp[k][n-k] : 0;
    printf("%d\n", (int)ans);
    return 0;
}
