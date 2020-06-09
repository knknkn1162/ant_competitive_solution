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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 50
#define K_MAX 50
#define ELEM_MAX 50
#define SUM_MAX (NUM_MAX*ELEM_MAX)

int main(void) {
    static int64_t dp[NUM_MAX+1][K_MAX+1][SUM_MAX+1];
    dp[0][0][0] = 1;
    int num, ave;
    get_int2(&num, &ave);
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i, j, k;
    for(i = 1; i <= num; i++) {
        int val = arr[i-1];
        for(k = 0; k <= i; k++) {
            for(j = 0; j <= k*ELEM_MAX; j++) {
                dp[i][k][j] += dp[i-1][k][j];
                if(k >= 1 && j >= val) dp[i][k][j] += dp[i-1][k-1][j-val];
            }
        }
    }
    int64_t ans = 0;
    for(k = 1; k <= num; k++) {
#ifdef DEBUG
        if(dp[i][k][ave*k])printf("dp[%d][%d][%d]=%lld\n", i, k, ave*k, dp[i][k][ave*k]);
#endif
        ans += dp[num][k][ave*k];
    }
    printf("%lld\n", ans);
    return 0;
}
