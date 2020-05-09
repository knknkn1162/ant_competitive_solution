#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define min3(a,b,c) min(min(a,b),c)

#define STR_MAX 100000
#define BUF_SIZE (STR_MAX+50)

int main(void) {
    static char str[BUF_SIZE];
    if(!fgets(str, BUF_SIZE, stdin)) return 0;
    int len = strlen(str) - 1;
    int i;
    for(i = 0; i < len; i++) str[i] = (str[i] == '1');

    int prev = str[i];
    int ans = STR_MAX+1;
    for(i = 0; i < len; i++) {
        if(prev == str[i]) continue;
        ans = min(ans, max(i, len-i));
        prev = str[i];
    }
    printf("%d\n", ans);
    return 0;
}
