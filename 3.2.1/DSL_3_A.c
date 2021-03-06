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

#define NUM_MAX 100000
#define INF (NUM_MAX+1)


int main(void) {
    int num, llimit;
    int arr[NUM_MAX];

    get_int2(&num, &llimit);
    fget_array(arr, num);

    int left;
    int right = 0;
    int sum = 0;
    int ans = INF;
    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            if(sum >= llimit) break;
            sum += arr[right];
        }
        // no need to search
        if(sum < llimit) break;
#ifdef DEBUG
        printf("%d %d -> %d\n", left, right, sum);
#endif
        ans = min(ans, right-left);
        sum -= arr[left];
    }
    printf("%d\n", ans == INF ? 0 : ans);
    return 0;
}
