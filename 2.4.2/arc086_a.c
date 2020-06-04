#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

#define NUM_MAX 200000

int desc(const void *a1, const void *a2) {
    return *(int*)a2 - *(int*)a1;
}

int main(void) {
    int num, k;
    get_int2(&num, &k);
    static int arr[NUM_MAX];
    fget_array(arr, num);
    
    int i;
    static int map[NUM_MAX+1];
    for(i = 0; i < num; i++) {
        map[arr[i]]++;
    }

    qsort(map, NUM_MAX+1, sizeof(int), desc);

    int ans = 0;
    for(i = k; i <= NUM_MAX; i++) {
        ans += map[i];
    }
    printf("%d\n", ans);
    return 0;
}
