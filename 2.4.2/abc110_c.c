#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}
#define NUM_MAX 200000
#define BUF_MAX (NUM_MAX+50)

int check(char *str1, char *str2, int len) {
    int i;
    char map[256] = {0};
    for(i = 0; i < len; i++) {
        if(!map[str1[i]]) {
            map[str1[i]] = str2[i];
            continue;
        }
        if(map[str1[i]] != str2[i]) return 0;
    }
    return 1;
}

int main(void) {
    static char sstr[BUF_MAX];
    static char tstr[BUF_MAX];
    get_str(sstr, BUF_MAX);
    get_str(tstr, BUF_MAX);

    // start == len
    int len = strlen(sstr);
    int flag = 1;
    flag &= check(sstr, tstr, len);
    flag &= check(tstr, sstr, len);
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}
