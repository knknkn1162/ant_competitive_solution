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

#define NUM_MAX 2000
#define LEN_MAX 1000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    qsort(arr, num, sizeof(int),asc);
    // 2 edges
    static int map[LEN_MAX*2+1];
    int i, j;
    for(i = 0; i < num; i++) {
        map[arr[i]]++;
    }
    for(i = 0; i <= LEN_MAX*2; i++) {
        map[i] += map[i-1];
    }

    int ans = 0;
    for(i = 0; i < num; i++) {
        for(j = i+1; j < num; j++) {
            int len = arr[i] + arr[j];
#ifdef DEBUG
            printf("%d-%d\n", map[len-1], j+1);
#endif
            ans += map[len-1] - (j+1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
