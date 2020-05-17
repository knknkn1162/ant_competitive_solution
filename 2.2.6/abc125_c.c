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

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+2];

    fget_array(&arr[1], num);

    static int cum[NUM_MAX+2];
    static int rcum[NUM_MAX+2];
    int i;
    for(i = 1; i <= num+1; i++) {
        int a = cum[i-1];
        int b = arr[i-1];
        if(a > b) swap(&a, &b);
        cum[i] = gcd(a, b);
    }

    for(i = num; i >= 0; i--) {
        int a = rcum[i+1];
        int b = arr[i+1];
        if(a > b) swap(&a, &b);
        rcum[i] = gcd(a, b);
    }

    int ans = 0;
    for(i = 1; i <= num; i++) {
        int a = cum[i]; // [1, i)
        int b = rcum[i]; // (i, num]
        if(a > b) swap(&a, &b);
        ans = max(ans, gcd(a, b));
    }
    printf("%d\n", ans);
    return 0;
}
