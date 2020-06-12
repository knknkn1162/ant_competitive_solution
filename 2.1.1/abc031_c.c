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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

int get_int5(int *a1, int *a2, int *a3, int *a4, int *a5) {
  scanf("%d %d %d %d %d", a1, a2, a3, a4, a5);
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

#define NUM_MAX 50
#define INF 10000

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    int i, j, k;
    int ans = -INF;
    for(i = 0; i < num; i++) {
        int res = 0;
        int aoki_max = -INF;
        for(j = 0; j < num; j++) {
            if(i==j) continue;
            int taka = 0;
            int aoki = 0;
            int i2 = min(i, j); int j2 = max(i, j);
            for(k = i2; k <= j2; k++) {
                int idx = k-i2+1;
                if(idx%2) {
                    taka += arr[k];
                } else {
                    aoki += arr[k];
                }
            }
            if(aoki_max < aoki) {
                res = taka;
                aoki_max = aoki;
            }
        }
#ifdef DEBUG
        printf("%d: %d aoki: %d\n", i, res, aoki_max);
#endif
        ans = max(res, ans);
    }
    printf("%d\n", ans);
    return 0;
}
