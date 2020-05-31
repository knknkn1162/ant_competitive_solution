#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
  int64_t num;
  scanf("%lld", &num);
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

#define STR_MAX 100
#define BUF_MAX (STR_MAX+10)
int main(void) {
    static char str[BUF_MAX];
    get_str(str, BUF_MAX);
    int len = strlen(str);
    int64_t pos = get_int();
    // 0-indexed
    pos--;

    int i;
    for(i = 0; i < len; i++) {
        if(str[i]!='1') break;
    }

    if(i > pos) {
        putchar(str[pos]);
    } else {
        putchar(str[i]);
    }
    putchar('\n');
    return 0;
}
