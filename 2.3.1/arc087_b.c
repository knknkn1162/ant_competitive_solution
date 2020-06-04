#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
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

#define STR_MAX 8000

struct point2d {
    int x;
    int y;
};
int main(void) {
    struct point2d goal;
    static char str[STR_MAX+1];
    get_str(str, STR_MAX+1);
    int len = strlen(str);
    str[len] = 'T'; // for guard
    get_int2(&goal.x, &goal.y);
    static int arr[STR_MAX+2];
    int aidx = 0;
    int i;
    for(i = 0; i < len+1; i++) {
        char ch = str[i];
        if(ch == 'F') {
            arr[aidx]++;
        } else { // 'T'
            aidx++;
        }
    }
    // if aidx is odd, make it even
    if(aidx%2 == 1) aidx++;
#ifdef DEBUG
    for(i = 0; i < aidx; i++) {
        printf(" %d", arr[i]);
    }
    putchar('\n');
#endif

    // for x
    static char dp[STR_MAX+5][2*STR_MAX+1];
    // ([0][len], [1][len]) = (.x=0, .y=0)
    dp[0][len+arr[0]] = 1;
    dp[1][len+arr[1]] = 1;
    dp[1][len-arr[1]] = 1;
    int pos;
    int flag_x = 0;
    int flag_y = 0;
    for(i = 2; i < aidx; i++) {
        int cnt = arr[i];
        for(pos = -len; pos <= len; pos++) {
            int ppos = pos+len;
            if(pos-cnt >= -len) dp[i][ppos] |= dp[i-2][ppos-cnt];
            if(pos+cnt <= len) dp[i][ppos] |= dp[i-2][ppos+cnt];
        }
    }

    flag_x = dp[aidx-2][len+goal.x]; // even
    flag_y = dp[aidx-1][len+goal.y]; // odd
#ifdef DEBUG
    printf("%d %d\n", flag_x, flag_y);
#endif
    printf("%s\n", (flag_x & flag_y) ? "Yes" : "No");
    return 0;
}
