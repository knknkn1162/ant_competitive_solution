#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define SET_MAX 100
#define BUF_SIZE 110

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

char table[][6] = {
    "tokyo",
    "kyoto",
    "AAAAA",
};

int main(void) {
    int num = get_int();
    int i, j, pos;
    char str[BUF_SIZE];
    int ans[SET_MAX];
    int aidx = 0;
    for(i = 0; i < num; i++) {
        get_str(str, BUF_SIZE);
        int len = strlen(str)-1;
        int mode = 2;
        int idx = 0;
        int cnt = 0;
        for(pos = 0; pos < len; pos++) {
#ifdef DEBUG
            printf("[%d] mode: %d, idx: %d\n", pos, mode, idx);
#endif
            if(str[pos] == table[mode][idx]) {
                idx++;
                if(idx == 5) { cnt++; idx = 0; mode = 2;}
                continue;
            }
            mode = 2; idx = 0;
            for(j = 0; j < 2; j++) {
                if(str[pos] == table[j][idx]) {
                    mode = j; break;
                }
            }
            if(mode!=2) { idx++; continue; }
        }
        ans[aidx++] = cnt;
    }
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
