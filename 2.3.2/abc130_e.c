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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 2000
#define DIVISOR 1000000007

int main(void) {
    int anum, bnum;
    get_int2(&anum, &bnum);
    static int arr[NUM_MAX];
    static int brr[NUM_MAX];
    fget_array(arr, anum);
    fget_array(brr, bnum);

    static int64_t dp[NUM_MAX+1][NUM_MAX+1];
    int i, j;
    for(i = 0; i <= anum; i++) dp[i][0] = 1;
    for(i = 0; i <= bnum; i++) dp[0][i] = 1;
    for(i = 1; i <= anum; i++) {
        int aval = arr[i-1];
        for(j = 1; j <= bnum; j++) {
            int bval = brr[j-1];
            int64_t ret = 0;
            ret = (ret + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + DIVISOR)%DIVISOR;
            if(aval == bval) {
                ret = (ret + dp[i-1][j-1])%DIVISOR;
            }
            dp[i][j] = ret;
        }
    }
    printf("%d\n", (int)dp[anum][bnum]);
    return 0;
}
