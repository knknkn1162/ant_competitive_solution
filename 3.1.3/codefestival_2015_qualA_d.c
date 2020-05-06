#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define max3(a,b,c) (max(max(a,b),c))
#define min(a,b) ((a) > (b) ? (b) : (a))

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        arr[i]--;
    }
    return 0;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}
#define PERSON_MAX 100000
#define NUM_MAX (2e+9)

int judge(int *arr, int ps, int trains, int64_t key) {
    int64_t yet = 0;
    int i;
    int flag = 0;
    for(i = 0; i < ps; i++) {
        int64_t cur = arr[i];
        if(yet >= cur) {
            yet = max(yet, cur + key + 1);
        } else {
            // If missing, failed
            if(cur-yet > key) break;
            int64_t move = (key - (cur-yet))/2;
            int64_t move2 = key - (cur-yet)*2;
            yet = max3(cur, cur + move, cur + move2) + 1;
        }
        if(yet >= trains) {
            flag = 1;
            break;
        }
    }
#ifdef DEBUG
    printf("key: %d -> %d: %d\n", key, yet, flag);
#endif
    return flag;
}

int main(void) {
    int num, ps;
    int arr[PERSON_MAX];
    get_int2(&num, &ps);
    fget_array(arr, ps);

    int64_t low = -1;
    int64_t high = NUM_MAX + 1;
    while(low + 1 < high) {
        int64_t mid = (low + high)/2;
        // lower bound
        if(judge(arr, ps, num, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%lld\n", high);
    return 0;
}
