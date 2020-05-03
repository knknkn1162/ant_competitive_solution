#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 110

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
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

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int asc(const void *a1, const void *a2) {
    return *(char*)a1 - *(char*)a2;
}

int main(void) {
    int num, ulimits;
    static char str[BUF_SIZE];
    get_int2(&num, &ulimits);
    get_str(str, BUF_SIZE);
    int len = strlen(str) - 1;
    if(ulimits==0 || ulimits==1) {
        goto finish;
    }

finish:
    printf("%.*s\n", len, str);
    return 0;
}
