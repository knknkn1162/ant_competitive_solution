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
#define BUF_SIZE (NUM_MAX+50)
#define STR_END ('z'+1)

struct pair {
    int left;
    int right;
};
int main(void) {
    static char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int len = strlen(str);
    str[len] = STR_END;

    int left;
    int right = 0;
    static int map[30];
    struct pair ans = {-1, -1};
    for(left = 0; left < len+1;) {
        char prev = STR_END;
        for(; right < len+1; right++) {
            if(map[prev-'a'] == 2) { break; }
            prev = str[right];
            map[prev - 'a']++;
        }

#ifdef DEBUG
        printf("%d %d\n", left, right);
#endif
        if(right == len+1) break;
        // left forward
        while(left < len+1) {
            int ch = str[left];
            map[ch-'a']--;
            left++;
            if(ch == prev) {
                if(right - left <= 2) {
                    ans = (struct pair){left-1+1, right-1+1};
                    goto finish;
                }
                break;
            }
        }
    }
finish:
    printf("%d %d\n", ans.left, ans.right);
    return 0;
}
