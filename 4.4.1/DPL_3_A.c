#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define min3(a,b,c) min(min(a,b),c)

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(char *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    return 0;
}

#define NUM_MAX 1400

int main(void) {
    int height, width;
    get_int2(&height, &width);
    static char mat[NUM_MAX+1][NUM_MAX+1];
    static int dp[NUM_MAX+1][NUM_MAX+1];
    int i, j;
    for(i = 1; i <= height; i++) {
        fget_array(&mat[i][1], width);
        // 0: dirty, 1: clean(usable)
        for(j = 1; j <= width; j++) mat[i][j] = 1-mat[i][j];
    }
#ifdef DEBUG
    for(i = 1; i <= height; i++) {
        for(j = 1; j <= width; j++) printf(" %d", mat[i][j]);
        putchar('\n');
    }
#endif

    int ans = 0;
    for(i = 1; i <= height; i++) {
        for(j = 1; j <= width; j++) {
            if(!mat[i][j]) { dp[i][j] = 0; continue; }
            dp[i][j] = 1;
            if(mat[i-1][j-1] && mat[i][j-1] && mat[i-1][j]) {
                dp[i][j] = min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
            }
            ans = max(dp[i][j], ans);
        }
    }

    printf("%d\n", ans*ans);
    return 0;
}
