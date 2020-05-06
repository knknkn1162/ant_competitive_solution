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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define ROOMS_MAX 100000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int calc_count(int *rooms, int size, int key) {
    int i;
    int prev = rooms[0];
    int cnt = 1;
    for(i = 1; i < size; i++) {
        int cur = rooms[i];
        if(cur - prev < key) continue;
        cnt++;
        prev = cur;
    }
#ifdef DEBUG
    printf("%d -> %d\n", key, cnt);
#endif
    return cnt;
}

int main(void) {
    int rs, cows;
    int rooms[ROOMS_MAX];
    get_int2(&rs, &cows);
    fget_array(rooms, rs);
    qsort(rooms, rs, sizeof(int), asc);
    int high = rooms[rs-1] - rooms[0];
    int low = -1;

    while(low + 1 < high) {
        int mid = (low + high)/2;
        // upper bound
        if(calc_count(rooms, rs, mid) >= cows) {
            low = mid;
        } else {
            high = mid;
        }
    }
    printf("%d\n", low);
    return 0;
}
