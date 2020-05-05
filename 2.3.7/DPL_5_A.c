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

int main(void) {
    int n, k;
    get_int2(&n, &k);
    uint64_t ans = 1;
    int i;
    for(i = 0; i < n; i++) {
        ans = (ans * k)%DIVISOR;
    }
    printf("%d\n", (int)ans);
    return 0;
}
