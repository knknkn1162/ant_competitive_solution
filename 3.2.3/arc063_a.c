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

#define NUM_MAX 100000

int main(void) {
    static char str[NUM_MAX];
    get_str(str, NUM_MAX);
    int len = strlen(str);

    char prev = str[0];
    int i;
    int cnt = 1;
    for(i = 1; i < len; i++) {
        if(prev != str[i]) cnt++;
        prev = str[i];
    }
    printf("%d\n", cnt-1);
    return 0;
}
