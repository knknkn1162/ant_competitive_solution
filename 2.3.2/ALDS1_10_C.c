#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define STR_MAX 1000
#define BUF_SIZE (STR_MAX+50)
#define SET_MAX 150

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

int main(void) {
    int num = get_int();
    static int dp[STR_MAX+1][STR_MAX+1];
    int i, j;
    int ans[SET_MAX];
    int aidx = 0;
    int set;
    for(set = 0; set < num; set++) {
        memset(dp, 0, sizeof(int)*(STR_MAX+1)*(STR_MAX+1));
        static char str1[BUF_SIZE];
        static char str2[BUF_SIZE];
        get_str(str1, BUF_SIZE);
        get_str(str2, BUF_SIZE);
        int len1 = strlen(str1) - 1;
        int len2 = strlen(str2) - 1;
        for(i = 1; i <= len1; i++) {
            char ch1 = str1[i-1];
            for(j = 1; j <= len2; j++) {
                char ch2 = str2[j-1];
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(ch1 == ch2) dp[i][j] = dp[i-1][j-1]+1;
            }
        }
        ans[aidx++] = dp[len1][len2];
    }
    
    for(i = 0; i < num; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
