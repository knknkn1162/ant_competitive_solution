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

#define NUM_MAX 100

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int lower_bound(int *arr, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main(void) {
    int num, selects;
    get_int2(&num, &selects);

    static int arr[NUM_MAX];
    fget_array(arr, num);

    int ans = 0;
    int k, i;
    for(k = 1; k <= min(num, selects); k++) {
        int max_remove = min(k, selects-k);
        int items[NUM_MAX] = {0};
        int left, right;
        for(left = 0; left <= k; left++) {
            int res = 0;
            right = num-(k-left);
            int idx = 0;
            for(i = 0; i < left; i++) {
                items[idx++] = arr[i];
            }
            for(i = right; i < num; i++) {
                items[idx++] = arr[i];
            }
            qsort(items, k, sizeof(int), asc);
#ifdef DEBUG
            printf("k :%d  : ", k);
            for(i = 0; i < k; i++) {
                printf(" %d", items[i]);
            }
            putchar('\n');
#endif
            int start = lower_bound(items, k, 0);
            start = min(start, max_remove);
            for(i = start; i < k; i++) {
                res += items[i];
            }
#ifdef DEBUG
            printf("[k: %d] [%d %d] -> %d\n", k, left, right, res);
#endif
            ans = max(res, ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
