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

#define NUM_MAX 100000

enum type {
    TYPE_ZERO,
    TYPE_POSITIVE,
};

int main(void) {
    static char str[NUM_MAX+2];

    int i;
    get_str(str, NUM_MAX);
    int len = strlen(str);
    str[len] = '+'; // for guard

#ifdef DEBUG
    printf("%s\n", str);
#endif
    int is_positive = 1;
    int ans = 0;
    for(i = 0; i < len+1; i++) {
        switch(str[i]) {
            case '+':
                ans += (is_positive==1);
                // reset
                is_positive = 1;
                break;
            case '*':
                // do nothing
                break;
            default: // number
                is_positive &= ((str[i] - '0') > 0);
                break;
        }
#ifdef DEBUG
        printf("is_positive: %d\n", is_positive);
#endif
    }
    printf("%d\n", ans);
    return 0;
}
