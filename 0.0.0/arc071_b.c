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
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100000

int main(void) {
    int xs, ys;
    get_int2(&xs, &ys);
    static int64_t xrr[NUM_MAX];
    static int64_t yrr[NUM_MAX];
    fget_array(xrr, xs);
    fget_array(yrr, ys);
    
    int i, j;
    int64_t prev_x = xrr[0];
    for(i = 1; i < xs; i++) {
        int64_t 
        for()
    }
    return 0;
}
