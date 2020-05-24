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

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// a < b
int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];
    fget_array(arr, num);

    int ans = arr[0];
    int i;
    for(i = 1; i < num; i++) {
        int val = arr[i];
        if(ans > val) swap(&ans, &val);
        ans = gcd(ans, val);
    }
    printf("%d\n", ans);
    return 0;
}
