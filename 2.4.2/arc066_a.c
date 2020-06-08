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
#define DIVISOR 1000000007

int check(int *arr, int num) {
    static int map[NUM_MAX+1];
    int i;
    int flag = 1;
    for(i = 0; i < num; i++) {
        map[arr[i]]++;
    }
    int start = (num%2==0) ? 1 : 2;
    if(num%2 == 1) {
        if(map[0] != 1) flag = 0;
    }
    for(i = start; i < num; i+=2) {
        if(map[i] != 2) flag = 0;
    }
    return flag;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    int64_t ans = 1;
    if(!check(arr, num)) {
        ans = 0;
    } else {
        for(i = 0; i < num/2; i++) {
            ans = (ans * 2)%DIVISOR;
        }
    }
    printf("%d\n", (int)ans);
}
