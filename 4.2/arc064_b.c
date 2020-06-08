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

int desc(const void *a1, const void *a2) {
    return *(int*)a2 - *(int*)a1;
}

int main(void) {
    static char str[NUM_MAX+5];
    get_str(str, NUM_MAX+5);
    int len = strlen(str);
    // winner => If odd: first, If even: second
    int win = (len+1)%2; // 0: first, 1: second

    static int map[26];
    int i;
    for(i = 0; i < len; i++) {
        map[str[i] - 'a']++;
    }
    static int sorted[26];
    memcpy(sorted, map, sizeof(int)*26);
    qsort(sorted, 26, sizeof(int), desc);
    // if(len==3) {
    //     if(sorted[0] == 2) win = 1;
    // } else 
    if(len%2 == 0) {
        // abca
        if(str[0] == str[len-1]) win = 0;
    } else {
        // odd
        // First player no longer take
        // if(sorted[0] == (len/2 + 1) && sorted[1] == len/2) {
        //     win = 1;
        // }
        if(str[0] == str[len-1]) win = 1;
        // anyway, First player wins.
        // else if(sorted[0] == len/2 && sorted[1] == len/2) {
        //     // abcab
        //     for(i = 0; i < 26; i++) {
        //         if(map[i]==1) break;
        //     }
        //     char ch = i+'a';
        //     if(str[0] != ch && str[len-1] != ch) win = 0;
        // }
    }
    printf("%s\n", win==0 ? "First" : "Second");
    return 0;
}
