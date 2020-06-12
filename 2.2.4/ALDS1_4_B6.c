#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

#define NUM_MAX 100000
#define QUERY_MAX 50000
#define INF ((1e+9)+1)

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    fget_array(arr, num);
    int qs = get_int();
    static int queries[NUM_MAX+1];
    fget_array(queries, qs);
    qsort(queries, qs, sizeof(int), asc);
    arr[num] = queries[qs] = INF;

    int k;
    int nidx = 0;
    int qidx = 0;
    int size = num + qs;
    int ans = 0;
    int prev = -1;
    for(k = 0; k < size; k++) {
        ans += (prev != arr[nidx] && arr[nidx] == queries[qidx]);
        if(arr[nidx] < queries[qidx]) {
            prev = arr[nidx];
            nidx++;
        } else {
            qidx++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
