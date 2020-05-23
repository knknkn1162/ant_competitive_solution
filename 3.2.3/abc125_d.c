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

#define NUM_MAX 100000
#define INF ((1e+9)+1)

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    int i;
    int sign = 0;
    int smallest = INF;
    int64_t ans = 0;
    for(i = 0; i < num; i++) {
        if(arr[i] < 0) sign++;
        int n = abs(arr[i]);
        smallest = min(n, smallest);
        ans += n;
    }
    if(sign%2 == 1) {
        ans -= smallest*2;
    }
    printf("%lld\n", ans);
    return 0;
}
