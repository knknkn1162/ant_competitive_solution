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
    int64_t limit;
    get_int2(&num, &limit);
    static int arr[NUM_MAX+1];
    // arr[0] = 0; // for guard
    fget_array(&arr[1], num);

    int i;
    int sum = 0;
    int64_t ans = 0;
    for(i = 1; i < num+1; i++) {
        // update arr[i]
        if(sum + arr[i] > limit) {
            // ensure that sum <= limit
            int dec = sum + arr[i] - limit;
            arr[i] -= dec;
            ans += dec;
        }
#ifdef DEBUG
        printf("ans: %lld\n", ans);
#endif
        // update sum
        sum += arr[i];
        sum -= arr[i-1];
    }
    printf("%lld\n", ans);
    return 0;
}
