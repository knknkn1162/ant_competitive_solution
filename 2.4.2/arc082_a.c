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

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int i;
    static int map[NUM_MAX+1];
    for(i = 0; i < num; i++) {
        map[arr[i]]++;
    }

    int ans = 0;
    for(i = 1; i < NUM_MAX; i++) {
        ans = max(ans, map[i-1] + map[i] + map[i+1]);
    }
    printf("%d\n", ans);
    return 0;
}
