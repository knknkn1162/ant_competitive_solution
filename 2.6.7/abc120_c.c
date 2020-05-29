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
#define NUM_MAX 100000
#define BUF_MAX (NUM_MAX+50)

int main(void) {
    static char str[NUM_MAX];
    get_str(str, BUF_MAX);
    int len = strlen(str);
    int i;
    static int map[2];
    for(i = 0; i < len; i++) {
        map[str[i]-'0']++;
    }
    printf("%d\n",len-abs(map[0]-map[1]));
    return 0;
}
