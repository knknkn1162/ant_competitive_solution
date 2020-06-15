#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t
#include <math.h>

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
#define ELEM_MAX 1000000

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    static int map[ELEM_MAX+1];
    int i;
    for(i = 0; i < num; i++) {
        map[arr[i]]++;
    }
    int ans = 0;
    if(map[1]==1) {
        ans = 1;
        goto finish;
    } else if (map[1] > 1) {
        ans = 0;
        goto finish;
    }

    int d;
    int cnt = 0;
    // assume that a[i] > 1 for all i
    for(i = 0; i < num; i++) {
        int val = arr[i];
        int val_2 = sqrt(0.5 + val);
        int flag = 0;
        if(map[val]>1) flag = 1;
        for(d = 2; d <= val_2; d++) {
            if(val%d) continue;
            if(map[d]) flag = 1;
            if(map[val/d]) flag = 1;
            if(flag) break;
        }
#ifdef DEBUG
        printf("%d -> flag: %d\n", i, flag);
#endif
        cnt += flag;
    }
    ans = num-cnt;
finish:
    printf("%d\n", ans);
    return 0;
}
