#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int64_t *a2) {
  scanf("%d %lld", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100000

int main(void) {
    int num;
    int64_t limit;
    get_int2(&num, &limit);
    static int64_t arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    int flag = 0;
    for(i = 0; i < num; i++) {
        if(!arr[i]) {
            flag = 1;
            break;
        }
    }
    if(flag) {
        printf("%d\n", num);
        return 0;
    }

    // ensure that all numbers and limits are positive
    int64_t sum = 1;
    int right = 0;
    int left = 0;
    int ans = 0;
    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            int64_t new = sum * arr[right];
            if(new > limit) break;
            sum = new;
        }
#ifdef DEBUG
        printf("[%d %d)\n", left, right);
#endif
        // if empty, go forward right
        if(left == right) { right++; continue; }
        ans = max(ans, right-left);
        sum /= arr[left];
    }
    printf("%d\n", ans);
    return 0;
}
