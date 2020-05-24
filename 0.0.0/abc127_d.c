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

#define NUM_MAX 100000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int lower_bound(int *arr, int num, int key) {
    int low = -1;
    int high = num;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

#define QUERY_MAX 100000

struct pair {
    int cards;
    int val;
};

int asc_by_val(const void *a1, const void *a2) {
    struct pair *pa1 = (struct pair*)a1;
    struct pair *pa2 = (struct pair*)a2;
    return pa1->val - pa2->val;
}

int main(void) {
    int num, queries;
    get_int2(&num, &queries);

    static int arr[NUM_MAX];
    fget_array(arr, num);
    qsort(arr, num, sizeof(int), asc);

    struct pair ps[QUERY_MAX];
    int i, j;
    for(i = 0; i < queries; i++) {
        int cards, val;
        get_int2(&cards, &val);
        ps[i] = (struct pair){cards, val};
    }
    qsort(ps, queries, sizeof(struct pair), asc_by_val);

    for(i = 0; i < queries; i++) {
        struct pair p = ps[i];
        int idx = lower_bound(arr, num, p.val);
        // arr[idx] < val, arr[idx+1] >= val
        if(p.cards >= idx+1) p.cards = idx+1; 
        int rem = (idx+1)- p.cards;
        // ifrem==0, do nothing
        memcpy(arr, &arr[p.cards], sizeof(int)*rem);
        for(j = rem; j < rem+p.cards; j++) arr[j] = p.val;
    }

    int64_t ans = 0;
    for(i = 0; i < num; i++) {
        ans += arr[i];
    }
    printf("%lld\n", ans);
    return 0;
}
