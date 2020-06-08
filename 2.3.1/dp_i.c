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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(double *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lf", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 3000

int main(void) {
    int num = get_int();
    static double dp[NUM_MAX+1][NUM_MAX/2+1];
    dp[0][0] = 1;

    static double arr[NUM_MAX];
    fget_array(arr, num);

    int i, j;
    // assume that num is odd
    for(i = 1; i <= num; i++) {
        double prob = arr[i-1];
        for(j = 0; j <= num/2; j++) {
            // front
            dp[i][j] += dp[i-1][j] * prob;
            // back
            if(j>=1) dp[i][j] += dp[i-1][j-1] * (1-prob);
        }
#ifdef DEBUG
        for(j = 0; j <= num/2; j++) {
            printf(" %lf", dp[i][j]);
        }
        putchar('\n');
#endif
    }
    double sum = 0;
    for(i = 0; i <= num/2; i++) {
        sum += dp[num][i];
    }
    printf("%.10lf\n", sum);
    return 0;
}
