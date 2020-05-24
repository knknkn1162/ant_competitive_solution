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



struct cands {
    int num;
    int cnt;
};

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(struct cands *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int val;
        scanf("%d", &val);
        arr[i] = (struct cands){val, 1};
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

int desc_by_num(const void *a1, const void *a2) {
    struct cands *ca1 = (struct cands*)a1;
    struct cands *ca2 = (struct cands*)a2;
    return ca2->num - ca1->num;
}


int main(void) {
    int num, queries;
    get_int2(&num, &queries);

    static struct cands arr[NUM_MAX+QUERY_MAX];
    fget_array(arr, num);
    int idx = num;

    int i;
    for(i = 0; i < queries; i++) {
        int cnt, val;
        get_int2(&cnt, &val);
        arr[idx++] = (struct cands){val, cnt};
    }

    qsort(arr, idx, sizeof(struct cands), desc_by_num);

    int64_t ans = 0;
    int rem = num;
    for(i = 0; i < idx; i++) {
        if(rem <= 0) break;
        int64_t picks = min(rem, arr[i].cnt);
        ans += (int64_t)arr[i].num * picks;
        rem -= picks;
    }

    printf("%lld\n", ans);

    return 0;
}
