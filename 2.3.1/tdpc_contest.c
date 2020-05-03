#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 100
#define ARR_MAX 100
#define SUM_MAX 10000
#define BUF_SIZE (ARR_MAX*4+50)

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
    int num = get_int();
    int arr[ARR_MAX];
    int dp[ARR_MAX+1][SUM_MAX];
    dp[0][0] = 1;
    fget_array(arr, num);
    int i, j;
    int sum = 0;
    for(i = 1; i <= num; i++) {
        int n = arr[i-1];
        sum += n;
        for(j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(j>=n) dp[i][j] |= dp[i-1][j-n];
        }
    }
    int cnt = 0;
    for(i = 0; i <= sum; i++) {
        cnt += dp[num][i];
    }
    printf("%d\n", cnt);
    return 0;
}
