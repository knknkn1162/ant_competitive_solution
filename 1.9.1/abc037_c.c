#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define min3(a,b,c) min(min(a,b),c)

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

#define NUM_MAX 100000

int main(void) {
    int num, len;
    get_int2(&num, &len);
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    int64_t ans = 0;
    int range_cnt = min(num-len+1, len);
    for(i = 0; i < num; i++) {
        int cnt = min3(i+1, num-i, range_cnt);
        ans += (int64_t)cnt * arr[i];
    }
    printf("%lld\n", ans);

    return 0;
}
