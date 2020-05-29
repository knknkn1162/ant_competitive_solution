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

int swap(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

int main(void) {
    int num, pos;
    static int arr[NUM_MAX];
    get_int2(&num, &pos);
    fget_array(arr, num);

    int i;
    int ans = 0;
    for(i = 0; i < num; i++) {
        int diff = abs(arr[i]-pos);
        int cur = ans;
        if(cur > diff) swap(&cur, &diff);
        ans = gcd(cur, diff);
    }
    printf("%d\n", ans);
    return 0;
}
