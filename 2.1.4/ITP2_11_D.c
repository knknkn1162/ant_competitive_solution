#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20
#define DIVISOR 1000000007

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

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

    int pat, i;
    for(pat = 0; pat < (1<<n); pat++) {
        if(__builtin_popcount(pat)!=k) continue;
        printf("%d:", pat);
        for(i = 0; i < n; i++) {
            if(!(pat & (1<<i))) continue;
            printf(" %d", i);
        }
        putchar('\n');
    }
    return 0;
}
