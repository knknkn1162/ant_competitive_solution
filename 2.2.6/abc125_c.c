#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

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

// a < b
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int gcd2(int a, int b) {
    if(a > b) swap(&a, &b);
    return gcd(a, b);
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+2];
    fget_array(&arr[1], num);

    static int cum[NUM_MAX+2];
    int i;
    for(i = 1; i <= num; i++) {
        cum[i+1] = gcd2(cum[i], arr[i]);
    }

    static int rcum[NUM_MAX+2];
    for(i = num; i >= 1; i--) {
        rcum[i-1] = gcd2(rcum[i], arr[i]);
    }

    int ans = 0;
    for(i = 1; i <= num; i++) {
        int res = gcd(cum[i], rcum[i]);
        ans = max(res, ans);
    }
    printf("%d\n", ans);
    return 0;
}
