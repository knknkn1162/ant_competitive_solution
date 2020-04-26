#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int main(void) {
    char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int len = strlen(str)-1;
    if(len == 1 && str[0] == 'a') {
        printf("%d\n", -1);
    } else {
        printf("a\n");
    }
    return 0;
}
