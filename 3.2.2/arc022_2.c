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
    static int map[NUM_MAX+1];
    int left;
    int right = 0;
    int ans = 0;
    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            if(map[arr[right]]) break;
            map[arr[right]]++;
        }
        ans = max(ans, right-left);
        map[arr[left]]--;
    }
    printf("%d\n", ans);
    return 0;
}
