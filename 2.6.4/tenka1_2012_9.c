#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 10

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

#define NUM_MAX 10000

int main(void) {
    int num = get_int();
    static char map[NUM_MAX+1];
    int i, j;
    for(i = 0; i <= num; i++) map[i] = 1;
    map[1] = 0;

    for(i = 2; i <= num; i++) {
        int limit = num/i;
        if(!map[i]) continue;
        for(j = 2; j <= limit; j++) {
            map[i*j] = 0;
        }
    }

    int ans = 0;
    for(i = 2; i < num; i++) {
        ans += map[i];
    }
    printf("%d\n", ans);
    return 0;
}
