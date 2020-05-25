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

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

#define NUM_MAX 100000

int main(void) {
    int comas, ps;
    get_int2(&comas, &ps);
    int points[NUM_MAX];
    fget_array(points, ps);
    if(comas >= ps) {
        printf("0\n");
        return 0;
    }
    qsort(points, ps, sizeof(int), asc);
    int diff[NUM_MAX];
    int i;
    for(i = 1; i < ps; i++) {
        diff[i-1] = points[i] - points[i-1];
    }

    qsort(diff, ps-1, sizeof(int), asc);
    int selects = ps-1 - (comas-1);
    int ans = 0;
    for(i = 0; i < selects; i++) {
        ans += diff[i];
    }

    printf("%d\n", ans);

    return 0;
}
