#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

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

int cnts[10] = {
    0,
    2,5,5,
    4,5,6,
    3,7,6
};

#define DP_MAX 36 // 10**18

int asc(const void *a1, const void *a2) { return *(int*)a1 - *(int*)a2; }

int main(void) {
    int num, kinds;
    get_int2(&num, &kinds);
    int arr[10];
    fget_array(arr, kinds);
    qsort(arr, kinds, sizeof(int), asc);
    int i, j;
    int consume = 10;
    int cdigit;
    for(i = kinds-1; i >= 0; i--) {
        int digit = arr[i];
        if(consume > cnts[digit]) {
            consume = cnts[digit];
            cdigit = digit;
        }
    }

    static int64_t dp[DP_MAX+1];
    for(i = 0; i <=DP_MAX; i++) dp[i] = -1;
    dp[0] = 0;
    for(i = kinds-1; i >= 0; i--) {
        int digit = arr[i];
        int cnt = cnts[digit];
        for(j = 0; j <= DP_MAX; j++) {
            if(j >= cnt) dp[j] = max(dp[j], dp[j-cnt]*10 + digit);
        }
    }
#ifdef DEBUG
    for(i = 0; i <= DP_MAX; i++) printf("%d -> %lld\n", i, dp[i]);
#endif
    

    // # of counts of digits
    static int cnt_map[10];
    int base_digit = cdigit;
    while(num > DP_MAX) {
        num -= consume;
        cnt_map[base_digit]++;
    }
    int64_t rem = dp[num];
    while(rem) {
        cnt_map[rem%10]++;
        rem /= 10;
    }

    // presentation
    for(i = 9; i >= 1; i--) {
        while(cnt_map[i]) {
            putchar('0' + i);
            cnt_map[i]--;
        }
    }
    putchar('\n');
    return 0;
}
