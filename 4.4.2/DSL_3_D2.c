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

#define NUM_MAX 1000000
#define NUM2_MAX (1<<20)
#define ROOT_NODE 1
#define INF (1e+9)

void update(int *seg, int num, int val, int idx) {
    int node = num + idx;
    seg[node] = val;
    while((node = node / 2)) {
        seg[node] = min(seg[node*2], seg[node*2+1]);
    }
    return;
}

int main(void) {
    int num, len;
    static int arr[NUM_MAX];
    static int ans[NUM_MAX];
    int aidx = 0;
    // Range Minimum Query
    static int seg[NUM2_MAX*2];
    get_int2(&num, &len);
    fget_array(arr, num);
    int len2 = 1;
    while(len > len2) len2 *= 2;
    int i;
    // initialization
    for(i = 0; i < len2*2; i++) {
        seg[i] = INF;
    }

    for(i = 0; i < num; i++) {
        int idx = i % len;
        update(seg, len2, arr[i], idx);
        if(i >= len-1) ans[aidx++] = seg[ROOT_NODE];
    }

    // presentation
    for(i = 0; i < aidx; i++) {
        printf("%d%c", ans[i], (i == aidx-1) ? '\n' : ' ');
    }
    return 0;
}
