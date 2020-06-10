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

int get_int2(int *a1, int64_t *a2) {
  scanf("%d %lld", a1, a2);
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
    int num;
    int64_t llimit;
    get_int2(&num, &llimit);
    int i;
    static int arr[NUM_MAX+1];
    fget_array(arr, num);

    int left;
    int right = 0;
    int64_t sum = 0;
    int64_t ans = 0;
    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            if(sum >= llimit) break;
            sum += arr[right];
        }
        if(sum < llimit) break;
        ans += num-(right-1);
        sum -= arr[left];
    }
    printf("%lld\n", ans);
    return 0;
}
