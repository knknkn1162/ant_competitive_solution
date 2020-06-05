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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

int get_int5(int *a1, int *a2, int *a3, int *a4, int *a5) {
  scanf("%d %d %d %d %d", a1, a2, a3, a4, a5);
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

#define NUM_MAX 1000

int main(void) {
    int anum, bnum;
    get_int2(&anum, &bnum);
    static int arr[NUM_MAX+1];
    static int brr[NUM_MAX+1];
    fget_array(arr, anum);
    fget_array(brr, bnum);
    arr[anum] = 0;
    brr[bnum] = 0;

    // 0: Nu's turn,  1: Me's turn
    static int dp[NUM_MAX+3][NUM_MAX+3][2];
    int a, b, i;
    // calc cumulative sum in advance
    static int arcum[NUM_MAX+1];
    for(i = anum-1; i >= 0; i--) {
        arcum[i] = arcum[i+1] + arr[i];
    }
    static int brcum[NUM_MAX+1];
    for(i = bnum-1; i >= 0; i--) {
        brcum[i] = brcum[i+1] + brr[i];
    }

    for(a = anum; a >= 0; a--) {
        for(b = bnum; b >= 0; b--) {
            for(i = 0; i < 2; i++) {
                int me = i;
                int you = (i+1)%2;
                int res = 0;
                // a's card is empty
                if(a == anum) {
                    res = brr[b] + dp[a][b+2][me];
                // b's card is empty
                } else if (b == bnum) {
                    res = arr[a] + dp[a+2][b][me];
                } else {
                    int sum = arcum[a] + brcum[b];
                    // Case1: take a
                    res = max(res, arr[a] + (sum-arr[a])-dp[a+1][b][you]);
                    // Case2: take b
                    res = max(res, arr[b] + (sum-arr[b])-dp[a][b+1][you]);
                }
#ifdef DEBUG
                printf("dp[%d][%d][%d] = %d\n", a,b,me, res);
#endif
                dp[a][b][me] = res;
            }
        }
    }
    printf("%d\n", dp[0][0][0]);
    return 0;
}
