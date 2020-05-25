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

#define NUM_MAX 100

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];
    fget_array(arr, num);
    int ans = 0;
    while(1) {
#ifdef DEBUG
        int i;
        printf("ans: %d: ", ans);
        for(i = 0; i < num; i++) printf(" %d", arr[i]);
        putchar('\n');
#endif
        int left, right;
        int cnt = 0;
        for(left = 0; left < num;) {
            if(!arr[left]) { left++; continue; }
            for(right = left; right < num; right++) {
                if(!arr[right]) break;
                arr[right]--; // watering
            }
            // [left, right)
            cnt++;
            // update left
            left = right+1;
        }
        if(!cnt) break;
        ans += cnt;
    }
    printf("%d\n", ans);
    return 0;
}
