#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))


#define NUM_MAX 100000

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

int main(void) {
    static char str[NUM_MAX];
    get_str(str, NUM_MAX);
    int len = strlen(str);

    int i;
    int point = 0;
    int pa = 0;
    for(i = 1; i < len; i++) {
        char cur = str[i];
        int gu = i-pa;
        if(cur == 'g') {
            if(gu > pa) {
                pa++; point++;
            }
        } else {
            if(gu <= pa) {
                // AtCodeer takes gu only
                point--;
            } else {
                // aiko
                pa++;
            }
        }
#ifdef DEBUG
        printf("round #%d -> %d %d\n", i+1, pa, point);
#endif
    }
    printf("%d\n", point);
    return 0;
}
