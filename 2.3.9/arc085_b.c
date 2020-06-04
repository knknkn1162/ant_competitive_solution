#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
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
// 2048
#define INF ((1e+9)+1)

enum type {
    TURN_X,
    TURN_Y,
};

int main(void) {
    int num, xscore, yscore;
    get_int3(&num, &xscore, &yscore);
    static int arr[NUM_MAX];
    fget_array(arr, num);
    int ans = 0;
    if(num == 1) {
        ans = abs(arr[num-1]-yscore);
    } else {
        ans = max(abs(arr[num-1]-yscore), abs(arr[num-2]-arr[num-1]));
    }
    printf("%d\n", ans);
    return 0;
}
