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

#define NUM_MAX 500000
struct range {
    int start;
    int end;
};
#define INF ((1e+9)+1)

int64_t cnt = 0;
void merge(int *arr, int size, struct range left, struct range right) {
    static int tmp1[NUM_MAX+1];
    static int tmp2[NUM_MAX+1];
    int i;
    // copy
    for(i = left.start; i < left.end; i++) tmp1[i] = arr[i];
    tmp1[i] = INF;
    for(i = right.start; i < right.end; i++) tmp2[i] = arr[i];
    tmp2[i] = INF;
    // int idx = left.start;
    // int ai, bi = right.start;
    // cnt += (right.end - left.start);
    // for(ai = left.start; ai < left.end; ai++) {
    //     for(; bi < right.end; bi++) {
    //         if(tmp1[ai] < tmp2[bi]) break;
    //         arr[idx++] = tmp2[bi];
    //     }
    //     arr[idx++] = tmp1[ai];
    // }
    int k;
    int ai = left.start;
    int bi = right.start;
    for(k = left.start; k < right.end; k++) {
        cnt++;
        if(tmp1[ai] <= tmp2[bi]) {
            arr[k] = tmp1[ai++];
        } else {
            arr[k] = tmp2[bi++];
        }
    }
    return;
}

void merge_sort(int *arr, int size, struct range r) {
#ifdef DEBUG
    printf("merge_sort(%d, %d)\n", r.start, r.end);
#endif
    if(r.start + 1 < r.end) {
        struct range left = (struct range){
            r.start, (r.start+r.end)/2
        };
        struct range right = (struct range){
            (r.start + r.end)/2, r.end
        };
        merge_sort(arr, size, left);
        merge_sort(arr, size, right);
        merge(arr, size, left, right);
    }
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    struct range whole = {0, num};
    // in-place sort
    merge_sort(arr, num, whole);

    // presentation
    int i;
    for(i = 0; i < num; i++) {
        printf("%d%c", arr[i], i==(num-1) ? '\n' : ' ');
    }
    printf("%lld\n", cnt);
    return 0;
}
