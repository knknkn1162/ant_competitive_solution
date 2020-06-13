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

#define NUM_MAX 100
#define INF (1e+9)

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    int sum = 0;
    for(i = 0; i < num; i++) {
        sum += arr[i];
    }
    int ave = sum / num;
    int n;
    int mmin = INF;
    for(n = ave-1; n <= ave+1; n++) {
        int res = 0;
        for(i = 0; i < num; i++) {
            res += (arr[i] - n) * (arr[i] - n);
        }
        mmin = min(res, mmin);
    }
    printf("%d\n", mmin);
    return 0;
}
