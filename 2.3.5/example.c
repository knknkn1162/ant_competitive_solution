/*
3 17
3 5 8
3 2 2
=> "Yes"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 100
#define K_MAX 100000
#define BUF_SIZE 1000

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

int main(void) {
    int num, k;
    get_int2(&num, &k);
    static int numbers[NUM_MAX+1];
    static int cnt[NUM_MAX+1];
    static int dp[NUM_MAX+1][K_MAX+1];
    int i, j;
    memset(dp, 0xff, sizeof(int)*(NUM_MAX+1)*(K_MAX+1));
    dp[0][0] = 0;

    fget_array(&numbers[1], num);
    fget_array(&cnt[1], num);
    for(i = 1; i <= num; i++) {
        for(j = 0; j <= k; j++) {
            if(dp[i-1][j]>=0) {
                dp[i][j] = cnt[i];
            } else {
                if(j-numbers[i]>=0) {
                    dp[i][j] = max(-1, dp[i][j-numbers[i]]-1);
                }
            }
        }
    }
    printf("%s\n", dp[num][k]>=0 ? "Yes" : "No");
    return 0;
}
