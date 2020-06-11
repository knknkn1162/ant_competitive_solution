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

#define DIGITS_MAX 10
#define NUM_MAX 1000000

void calc_digit(int num, int *map) {
    while(num) {
        map[num%10] = 1;
        num /= 10;
    }
    return;
}

int main(void) {
    int num, k;
    get_int2(&num, &k);
    int arr[DIGITS_MAX];
    fget_array(arr, k);
    static int xs[10];
    int i, j;
    for(i = 0; i < k; i++) xs[arr[i]] = 1;
    int ans = 0;
    for(i = num; i <= NUM_MAX; i++) {
        int map[10] = {0};
        calc_digit(i, map);
        int flag = 1;
        for(j = 0; j < 10; j++) {
            if(xs[j] == 1 && map[j] == 1) flag = 0;
        }
        if(flag) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
