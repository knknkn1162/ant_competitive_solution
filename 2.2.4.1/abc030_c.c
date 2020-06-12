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
#define INF ((1e+9)+1)

enum port {
    PORT_A,
    PORT_B
};

int main(void) {
    int anum = get_int();
    int bnum = get_int();

    int aflight, bflight;
    get_int2(&aflight, &bflight);
    static int arr[NUM_MAX+1];
    static int brr[NUM_MAX+1];
    fget_array(arr, anum);
    fget_array(brr, bnum);
    arr[anum] = INF;
    brr[bnum] = INF;

    int aidx = 0;
    int bidx = 0;

    int k;
    int size = anum + bnum;
    int cur = 0;
    int pos = 0; // port A
    int cnt = 0;
    for(k = 0; k < size; k++) {
        if(arr[aidx] < brr[bidx]) {
            if(pos == PORT_A && cur <= arr[aidx]) {
                pos = PORT_B;
                cur = arr[aidx] + aflight;
                cnt++;
            }
            aidx++;
        } else {
            if(pos == PORT_B && cur <= brr[bidx]) {
                pos = PORT_A;
                cur = brr[bidx] + bflight;
                cnt++;
            }
            bidx++;
        }
    }
    printf("%d\n", cnt/2);
    return 0;
}
