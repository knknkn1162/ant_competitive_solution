#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
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

#define NUM_MAX 100000
#define K_MAX 100000
#define INF (NUM_MAX+1)

int main(void) {
    int num, ulimit;
    int arr[NUM_MAX];
    get_int2(&num, &ulimit);

    fget_array(arr, num);

    int left;
    int right = 0;
    static int map[K_MAX+1];
    int cnt = 0;
    int ans = INF;

    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            if(cnt == ulimit) break;
            int cur = arr[right];
            if(cur > ulimit) continue; // ignore map
            if(!map[cur]) cnt++;
            map[cur]++;
        }
        if(cnt != ulimit) break;
        ans = min(ans, right - left);
        map[arr[left]]--;
        if(!map[arr[left]]) cnt--;
    }

    printf("%d\n", ans == INF ? 0 : ans);
    
    return 0;
}
