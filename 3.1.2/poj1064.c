#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int100(void) {
  int d1; int d2;
  scanf("%d.%d", &d1, &d2);
  return d1*100+d2;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

#define NUM_MAX 10000
#define UNIT_MAX 100000

int judge(int *arr, int size, int key, int ropes) {
    int i;
    int ans = 0;
    for(i = 0; i < size; i++) {
        ans += (int)(arr[i]/key);
        if(ans >= ropes) return 1;
    }
    return 0;
}


int main(void) {
    int num, ropes;
    int i;
    int arr[NUM_MAX];

    get_int2(&num, &ropes);
    for(i = 0; i < num; i++) {
        arr[i] = get_int100();
    }

    int low = 0;
    int high = UNIT_MAX*100+1;
    while(low+1 < high) {
        int mid = (low + high)/2;
        if(judge(arr, num, mid, ropes)) {
            low = mid;
        } else {
            high = mid;
        }
#ifdef DEBUG
        printf("%d %d\n", low, high);
#endif
    }

    printf("%d.%02d\n", low/100, low%100);
    return 0;
}
