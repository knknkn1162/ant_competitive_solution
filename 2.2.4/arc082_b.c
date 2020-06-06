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

#define NUM_MAX 100000

void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    fget_array(&arr[1], num);

    int i;
    int ans = 0;
    for(i = 1; i <= num-1; i++) {
        if(arr[i] == i) {
            swap(&arr[i], &arr[i+1]);
            ans++;
        }
    }
    // swap anyway
    if(arr[num] == num) ans++;
    printf("%d\n", ans);
    return 0;
}
