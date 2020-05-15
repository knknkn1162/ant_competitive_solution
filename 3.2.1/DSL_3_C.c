#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
  int64_t num;
  scanf("%lld", &num);
  return num;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
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
#define INF (int64_t)(1e+14)

int main(void) {
    int num, qs;
    get_int2(&num, &qs);

    static int64_t arr[NUM_MAX+1];
    fget_array(arr, num);
    arr[num] = INF; // guard
    int i;
    for(i = 0; i < qs; i++) {
        int64_t q = get_int();
        int64_t sum = 0;
        int64_t cnt = 0;
        int right = 0;
        int left;
        for(left = 0; left < num+1; left++) {
            // sum is always sum <= q
            for(; right < num+1; right++) {
                if(sum > q) break;
                sum += arr[right];
            }
#ifdef DEBUG
            printf("[%d, %d)\n", left, right);
#endif
            cnt += (right - left - 1);
            sum -= arr[left];
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
