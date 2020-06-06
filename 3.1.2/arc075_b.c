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

int64_t count(int *arr, int size, int attack, int64_t cum) {
    int i;
    int64_t cnt = 0;
    for(i = 0; i < size; i++) {
        int64_t hp = arr[i]-cum;
        if(hp<=0) continue;
        cnt += (hp-1)/attack + 1;
    }
#ifdef DEBUG
    printf("%lld -> cnt: %lld\n", cum, cnt);
#endif
    return cnt;
}

#define NUM_MAX 100000
int main(void) {
    int num, center, neigh;
    get_int3(&num, &center, &neigh);

    static int arr[NUM_MAX];
    fget_array(arr, num);

    int low = 0;
    int high = (1e+9)+1;
    while(low + 1 < high) {
        int64_t mid = (low + high) / 2;
        int64_t cum = (int64_t)mid * neigh;
        // lower bound; count maybe higher than INT_MAX if mid is too low
        if(count(arr, num, center-neigh, cum) <= mid) {
            high = mid;
        } else {
            low = mid;
        }
#ifdef DEBUG
        printf("mid: %d\n", mid);
#endif
    }

    printf("%d\n", high);

    return 0;
}
