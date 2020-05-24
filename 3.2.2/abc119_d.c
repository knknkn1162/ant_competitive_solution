#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
    int64_t ans;
    scanf("%lld", &ans);
    return ans;
}
int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
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

void get_shortest(int64_t *arr, int anum, int64_t *brr, int bnum, int64_t *out) {
    int left, right = 0;
    for(left = 0; left < anum; left++) {
        for(; right < bnum; right++) {
            if(brr[right] > arr[left]) break;
        }
        
        int64_t res = labs(brr[right] - arr[left]);
        if(right != 0) res = min(res, labs(brr[right-1] - arr[left]));
        out[left] = res;
    }
    return;
}
#define INF (int64_t)(1e+11)
#define QUERY_MAX 100000

int lower_bound(int64_t *arr, int size, int64_t key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(void) {
    int anum, bnum;
    int queries;
    get_int3(&anum, &bnum, &queries);

    static int64_t arr[NUM_MAX];
    static int64_t brr[NUM_MAX];
    // already sorted
    fget_array(arr, anum);
    fget_array(brr, bnum);

    static int64_t ashortest[NUM_MAX];
    static int64_t bshortest[NUM_MAX];
    get_shortest(arr, anum, brr, bnum, ashortest);
    get_shortest(brr, bnum, arr, anum, bshortest);

    int i, j;
    static int64_t ans[QUERY_MAX];
    int idx = 0;
    for(i = 0; i < queries; i++) {
        int64_t x = get_int();
        int64_t res = INF;
        int aidx = lower_bound(arr, anum, x);
        // for A -> B
        for(j = aidx; j < anum; j++) {
            if(j < 0) continue;
            if(j > aidx+1) break;;
            res = min(res, labs(x-arr[j])+ashortest[j]);
        }
        // for B -> A
        int bidx = lower_bound(brr, bnum, x);
        for(j = bidx; j < bnum; j++) {
            if(j < 0) continue;
            if(j > bidx+1) break;;
            res = min(res, labs(x-brr[j])+bshortest[j]);
        }
        ans[idx++] = res;
    }

    for(i = 0; i < idx; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
