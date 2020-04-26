#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 100050

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

char table[4][10] = {
    "maerd",
    "remaerd",
    "esare",
    "resare",
};

int lens[4] = {
    5,7,5,6
};

enum {
    ENUM_DREAM,
    ENUM_DREAMER,
    ENUM_ERASE,
    ENUM_ERASER,
    ENUM_ALL,
};

#define ALL_STATE ((1<<ENUM_ALL)-1)

int main(void) {
    char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int len = strlen(str)-1;
    int pos;
    int cur_state = ALL_STATE;
    int idx = 0;
    int i;
    int flag = 1;
    for(pos = len-1; pos >= 0; pos--) {
#ifdef DEBUG
        printf("[%d: %c] %d\n", pos, str[pos], cur_state);
#endif
        int next_state = 0;
        for(i = 0; i < ENUM_ALL; i++) {
            if(!(cur_state & (1<<i))) continue;
            if(str[pos] == table[i][idx]) {
                next_state |= (1<<i);
            }
        }
        cur_state = next_state;
        idx++;
        for(i = 0; i < ENUM_ALL; i++) {
            if(!(cur_state & (1<<i))) continue;
            if(lens[i] == idx) {
                idx = 0;
                cur_state = ALL_STATE;
                break;
            }
        }
        // impossible to move back
        if(cur_state == 0) { flag = 0; break; }
    }
    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}
