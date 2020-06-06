#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

#define STR_MAX 210

int main(void) {
    static char str[STR_MAX];
    get_str(str, STR_MAX);
    int len = strlen(str);

    int i;
    for(i = len/2-1; i >= 1; i--) {
        if(strncmp(str, &str[i], i) == 0) break;
    }
    printf("%d\n", i*2);
}
