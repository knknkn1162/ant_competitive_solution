#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int64_t *a2) {
  scanf("%d %lld", a1, a2);
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
#define PROD_MAX (int64_t)(1e+18)

int64_t get_count(int *arr, int asize, int *brr, int bsize, int64_t key) {
    int is_same = (arr == brr);
    int64_t counter = 0;
    int i;
    for(i = 0; i < asize; i++) {
        int low = (is_same) ? i : -1;
        int high = bsize;
        // binary search
        while(low + 1 < high) {
            int mid = (low + high)/2;
            int64_t prod = (int64_t)arr[i] * (int64_t)brr[mid];
            if(prod < key) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if(is_same) {
            counter += (low-i);
        } else {
            counter += (low+1);
        }
    }
    return counter;
}

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num;
    int64_t k;
    int arr[NUM_MAX];
    int pos_arr[NUM_MAX];
    int neg_arr[NUM_MAX];
    get_int2(&num, &k);
    fget_array(arr, num);
    int64_t negs = 0;
    int64_t poss = 0;
    int64_t zeros = 0;
    int i;
    for(i = 0; i < num; i++) {
        if(arr[i] < 0) {
            neg_arr[negs++] = arr[i];
        } else if (arr[i] == 0) {
            zeros++;
        } else {
            pos_arr[poss++] = arr[i];
        }
    }
    qsort(neg_arr, negs, sizeof(int), asc);
    qsort(pos_arr, poss, sizeof(int), asc);
#ifdef DEBUG
    printf("pos: %lld, neg: %lld, zeros: %lld\n", poss, negs, zeros);
#endif

    int64_t neg_counts = negs * poss;
    int64_t low, high;
    // ans is negative number
    int64_t zero_counts = zeros * (negs + poss) + (zeros * (zeros-1))/2;
    int flag = 0;
    int64_t ans = 0;
#ifdef DEBUG
    printf("%lld %lld %lld\n", neg_counts, zero_counts, (poss*(poss-1)/2) + (negs*(negs-1)/2));
#endif
    if(neg_counts >= k) {
        flag = -1;
    } else if (neg_counts + zero_counts >= k) {
        // no need to search
        goto finish;
    } else {
        flag = 1;
    }

    if(flag == -1) {
        low = -PROD_MAX - 1;
        high = 0;
    } else {
        // ans is positive
        low = 0;
        high = PROD_MAX + 1;
        k -= (neg_counts + zero_counts);
    }
#ifdef DEBUG
    printf("flag: %d, k: %lld\n", flag, k);
#endif
    while(low + 1 < high) {
        int64_t mid = (low + high)/2;
        int64_t counts;
        if(flag == -1) {
            // search within negative
            counts = get_count(neg_arr, negs, pos_arr, poss, mid);
        } else {
            counts = get_count(neg_arr, negs, neg_arr, negs, mid) + get_count(pos_arr, poss, pos_arr, poss, mid);
        }
#ifdef DEBUG
        printf("%lld -> count: %lld\n", mid, counts);
#endif
        // mid is below #k-1
        if(counts < k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    ans = low;
finish:
    printf("%lld\n", ans);
    return 0;
}
