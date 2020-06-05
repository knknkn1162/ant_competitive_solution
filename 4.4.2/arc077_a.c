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

#define NUM_MAX 200000

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    static int deque[NUM_MAX*2];
    int start = NUM_MAX;
    int end = NUM_MAX;

    int i;
    int dir = 1;
    for(i = 0; i < num; i++) {
        int val = arr[i];
        if(i%2==0) {
            deque[end++] = val;
        } else {
            deque[--start] = val;
        }
        dir = -dir;
    }

    if(dir==1) {
        // str is [start, end)
        for(i = start; i < end; i++) {
            printf("%d%c", deque[i], i == end-1 ? '\n' : ' ');
        }
    } else {
        for(i = end-1; i >= start; i--) {
            printf("%d%c", deque[i], i == start ? '\n' : ' ');
        }
    }
    return 0;
}
