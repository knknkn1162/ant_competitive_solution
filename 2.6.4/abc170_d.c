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
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 200000
#define VAL_MAX 1000000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    qsort(arr, num, sizeof(int), asc);
    static char dp[VAL_MAX+1];
    memset(dp, 0x01, sizeof(char)*(VAL_MAX+1));
    int i, j;
    int prev = 0;
    // sieve of eratosthenes
    for(i = 0; i < num; i++) {
        int val = arr[i];
        if(!dp[val]) continue;
        // important!!
        if(val == prev) {
            dp[val] = 0;
            continue;
        }
        prev = val;
        int ulimit = VAL_MAX/val;
        for(j = 2; j <= ulimit; j++) {
            dp[val*j] = 0;
        }
    }
    int cnt = 0;
    for(i = 0; i < num; i++) {
        cnt += dp[arr[i]];
    }
    printf("%d\n", cnt);
    return 0;
}
