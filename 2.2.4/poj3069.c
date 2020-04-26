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

#define NUM_MAX 1000
#define INF 10000

int lower_bound(int *arr, int size, int key) {
    int low = -1;
    int high = size;
    while(low+1 < high) {
        int middle = (low + high) / 2;
        if(arr[middle] > key) {
            high = middle;
        } else {
            low = middle;
        }
    }
    return high;
}

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

#define SET_MAX 100000

int main(void) {
    static int arr[NUM_MAX+1];
    static int ans[SET_MAX];
    int aidx = 0;
    int i;
    while(1) {
        int range, num;
        get_int2(&range, &num);
        if(range == -1 && num == -1) break;
        memset(arr, 0, sizeof(int)*(NUM_MAX+1));
        fget_array(arr, num);
        qsort(arr, num, sizeof(int), asc);
        arr[num] = INF; // guard
        int uncover = 0;
        int cnt = 0;
        for(i = 0; i < num+1; i++) {
            if(uncover >= i) continue;
            if(arr[i]-range <= arr[uncover]) continue;
            // cover by arr[i-1]
            int until = arr[i-1] + range;
            uncover = lower_bound(arr, num+1, until);
#ifdef DEBUG
            printf("@ [idx: %d]%d -> new uncover: %d\n", arr[i-1], i-1, uncover);
#endif
            cnt++;
        }
        ans[aidx++] = cnt;
    }
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
