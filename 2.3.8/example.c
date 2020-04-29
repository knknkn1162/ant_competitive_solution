/*
M
n m
a_1 .. a_n

ex)
10000
3 3
1 2 3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

#define NUM_MAX 1000
#define SELECT_MAX 1000
#define BUF_SIZE (NUM_MAX*5+50)

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
    int divisor = get_int();
    static int dp[NUM_MAX+1][SELECT_MAX+1];
    dp[0][0] = 1;
    int num, sels;
    int arr[NUM_MAX];
    static int cum[SELECT_MAX+2];
    get_int2(&num, &sels);
    fget_array(arr, num);
    int j;
    for(j = 1; j <= sels+1; j++) {
        cum[j] = cum[j-1] + dp[0][j-1];
    }

    int i, cur;
    for(i = 1; i <= num; i++) {
        int limit = arr[i-1];
        for(cur = 0; cur <= sels; cur++) { // max: 1000
            // sum of [max(0, cur-limit), cur]
            dp[i][cur] = (divisor + cum[cur+1] - cum[max(0, cur-limit)])%divisor;
        }
        memset(cum, 0, sizeof(int)*(NUM_MAX+2));
        for(j = 1; j <= sels+1; j++) {
            cum[j] = (cum[j-1] + dp[i][j-1])%divisor;
        }
    }
    printf("%d\n", dp[num][sels]);
    return 0;
}
