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

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    fget_array(&arr[1], num);
    static int map[NUM_MAX+1];
    int i;
    // A_i + i = j - A_j
    for(i = 1; i <= num; i++) {
        int val = arr[i]+i;
        if(val <= NUM_MAX) map[val]++;
    }

    int64_t ans = 0;
    for(i = num; i >= 1; i--) {
        int val = arr[i]+i;
        if(val <= NUM_MAX) map[val]--;
        // j > i
        int jval = i-arr[i];
        if(jval >= 0) ans += map[jval];
    }

    printf("%lld\n", ans);
    return 0;
}
