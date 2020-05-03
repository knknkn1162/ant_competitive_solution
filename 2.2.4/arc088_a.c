#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 50

int get_int2(uint64_t *a1, uint64_t *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%llu %llu", a1, a2);
#else
#error
#endif
  return 0;
}

int main(void) {
    uint64_t start, end;
    get_int2(&start, &end);
    int cnt = 0;
    while(start <= end) {
        start *= 2;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
