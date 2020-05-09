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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
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
#define LADDER_MAX 100000

struct ladder {
    int start;
    int height;
};

int asc(const void *a1, const void *a2) {
    return 
}

int main(void) {
    int arr[NUM_MAX];
    struct ladder ladders[LADDER_MAX];
    int num, ls, height, k;
    get_int4(&num, &ls, &height, &k);
    fget_array(arr, num);
    int i;
    for(i = 0; i < ls; i++) {
        get_int2(&ladders[i].start, &ladders[i].height);
    }

    qsort(ladders, ls, sizeof(struct ladder), asc);
    return 0;
}
