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

#define BUF_SIZE 100

int asc(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int desc(const void *a, const void *b) {
    return *(char*)b - *(char*)a;
}

int main(void) {
    static char str1[BUF_SIZE];
    static char str2[BUF_SIZE];
    // we hope that str1 < str2;
    get_str(str1, BUF_SIZE);
    get_str(str2, BUF_SIZE);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    qsort(str1, len1, sizeof(char), asc);
    qsort(str2, len2, sizeof(char), desc);
#ifdef DEBUG
    printf("%s vs %s\n", str1, str2);
#endif

    printf("%s\n", strncmp(str1, str2, BUF_SIZE)<0 ? "Yes" : "No");
    return 0;
}
