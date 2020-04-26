#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 55

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

#define UNKNOWN '?'

int compare(char *s, char *t, int len) {
    int i;
    int flag = 1;
    for(i = 0; i < len; i++) {
        if(s[i] == UNKNOWN) continue;
        if(s[i] != t[i]) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(void) {
    char str[BUF_SIZE];
    char sub[BUF_SIZE];
    get_str(str, BUF_SIZE);
    get_str(sub, BUF_SIZE);
    int slen = strlen(str)-1;
    int tlen = strlen(sub)-1;
    int i, j;

    int flag = 0;
    for(i = slen-tlen; i >= 0; i--) {
        if(compare(&str[i], sub, tlen)) {
            flag = 1;
            memcpy(&str[i], sub, tlen);
            for(j = 0; j < slen; j++) {
                if(str[j] == UNKNOWN) str[j] = 'a';
            }
            break;
        }
    }
    printf("%s", flag ? str : "UNRESTORABLE\n");
    return 0;
}
