#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define DIVISOR 1000000007
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

#define NUM_MAX 1000

int main(void) {
    int num = get_int();
    static int map[NUM_MAX+1];

    int i;
    for(i = 2; i <= num; i++) {
        int n = i;
        int div = 2;
        while(n>1) {
            if(n%div) { // cannot devide
                div++;
                continue;
            }
            map[div]++;
            n = n / div;
        } 
    }

    uint64_t ans = 1;
    for(i = 2; i <= num; i++) {
        ans = (ans * (map[i]+1))%DIVISOR;
    }
    printf("%d\n", (int)ans);
}
