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

int main(void) {
    int num = get_int();
    int walk, tel;
    get_int2(&walk, &tel);
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int start = arr[0];
    int i;
    int64_t ans = 0;
    for(i = 1; i < num; i++) {
        int end = arr[i];
        int power = min((int64_t)(end-start)*walk, tel);
        ans += power;
        start = end;
    }
    printf("%lld\n", ans);
    return 0;
}
