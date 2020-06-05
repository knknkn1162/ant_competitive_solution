#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define NUM_MAX 52
#define BUF_SIZE (NUM_MAX+10)
#define DIVISOR 1000000007

enum type {
    TYPE_EMPTY,
    TYPE_VERTICAL,
    TYPE_HORIZONTAL,
};

int main(void) {
    int num = get_int();
    static char str[2][NUM_MAX];
    get_str(str[0], num);
    get_str(str[1], num);

    int i;
    int64_t res = 1;
    int prev = TYPE_EMPTY;
    int cur;
    for(i = 0; i < num; i++) {
        // set domino vertically
        if(str[0][i] == str[1][i]) {
            cur = TYPE_VERTICAL;
            if(prev == TYPE_EMPTY) {
                res = (res * 3)%DIVISOR;
            } else if(cur == prev) {
                res = (res * 2)%DIVISOR;
            }
        // set domino horizontally
        } else {
            cur = TYPE_HORIZONTAL;
            if(prev == TYPE_EMPTY) {
                res = (res * 6)%DIVISOR;
            } else if (prev == TYPE_VERTICAL) {
                res = (res * 2)%DIVISOR;
            } else {
                res = (res * 3)%DIVISOR;
            }
            // skip
            i++;
        }
#ifdef DEBUG
        printf("%d[cur: %d]: %lld\n", i, cur, res);
#endif
        prev = cur;
    }
    printf("%d\n", (int)res);
    return 0;
}
