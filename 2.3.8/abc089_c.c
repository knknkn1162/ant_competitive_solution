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

#define STR_MAX 10
#define BUF_SIZE (STR_MAX+10)

int main(void) {
    int num = get_int();
    int i;
    static int map[26];
    for(i = 0; i < num; i++) {
        char str[BUF_SIZE];
        get_str(str, BUF_SIZE);
        map[str[0]-'A']++;
    }
    int64_t ans = 0;
    static char keyword[] = "MARCH";
    int pat, bit;
    for(pat = 0; pat < (1<<5); pat++) {
        if(__builtin_popcount(pat)!=3) continue;
        int64_t res = 1;
        for(bit = 0; bit < 5; bit++) {
            if(!(pat & (1<<bit))) continue;
            res *= map[keyword[bit]-'A'];
        }
#ifdef DEBUG
        printf("%lld\n", res);
#endif
        ans += res;
    }
    printf("%lld\n", ans);
    return 0;
}
