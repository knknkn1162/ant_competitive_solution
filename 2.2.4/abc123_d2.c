#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
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

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}

#define CANDS_MAX 500000

int main(void) {
    int x, y, z, rank;
    get_int4(&x, &y, &z, &rank);
    static int64_t xrr[NUM_MAX+1];
    static int64_t yrr[NUM_MAX+1];
    static int64_t zrr[NUM_MAX+1];
    // 1-indexed
    fget_array(&xrr[1], x);
    fget_array(&yrr[1], y);
    fget_array(&zrr[1], z);

    qsort(&xrr[1], x, sizeof(int64_t), desc);
    qsort(&yrr[1], y, sizeof(int64_t), desc);
    qsort(&zrr[1], z, sizeof(int64_t), desc);

    static int64_t cands[CANDS_MAX];
    int cidx = 0;
    int i, j, k;

    for(i = 1; i <= x; i++) {
        for(j = 1; j <= y; j++) {
            for(k = 1; k <= z; k++) {
                if(i*j*k > rank) break;;
                cands[cidx++] = xrr[i] + yrr[j] + zrr[k];
            }
        }
    }
    qsort(cands, cidx, sizeof(int64_t), desc);

    for(i = 0; i < rank; i++) {
        printf("%lld\n", cands[i]);
    }
    return 0;
}
