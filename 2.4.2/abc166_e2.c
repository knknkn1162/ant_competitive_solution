#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

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

#define HASH_SIZE 65536

#define NUM_MAX 200000

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    static int map[NUM_MAX];

    fget_array(&arr[1], num);
    int i;
    // 0 < a2 - h2 = h1 + a1 < NUM_MAX
    for(i = 1; i <= num; i++) {
        // diff
        if(i - arr[i] >= 0) map[i-arr[i]]++;
    }
    int64_t ans = 0;
    for(i = 1; i <= num; i++) {
        int sum = arr[i] + i;
        if(sum >= NUM_MAX) continue;
        if(i - arr[i] >= 0) map[i-arr[i]]--;
        ans += map[sum];
    }
    printf("%lld\n", ans);
}
