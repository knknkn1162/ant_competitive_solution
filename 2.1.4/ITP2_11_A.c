#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 10
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


int main(void) {
    int num = get_int();
    int pat = 0;
    int i;
    for(pat = 0; pat < (1<<num); pat++) {
        printf("%d:", pat);
        int pos[18] = {0};
        int idx = 0;
        for(i = 0; i < num; i++) {
            if(pat & (1<<i)) pos[idx++] = i;
        }
        for(i = 0; i < idx; i++) {
            printf(" %d", pos[i]);
        }
        putchar('\n');
    }
    return 0;
}
