#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int64_t *a2) {
  scanf("%d %lld", a1, a2);
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

#define NUM_MAX 200000

int main(void) {
    int num;
    int arr[NUM_MAX+1];
    int64_t changes;
    get_int2(&num, &changes);

    fget_array(&arr[1], num);

    int pos[NUM_MAX*2+1];
    static int idx_map[NUM_MAX+1];
    int i;
    for(i = 0; i <= NUM_MAX; i++) idx_map[i] = -1;
    int pidx = 0;
    pos[pidx++] = 1;
    idx_map[1] = 0;
    int cycle_start = 0;
    int cycle_end = 0;
    for(i = 1; i <= NUM_MAX*2; i++) {
        int cur = pos[i-1];
        int next = arr[cur];
        if(idx_map[next] != -1) {
            cycle_start = idx_map[next];
            cycle_end = i;
            break;
        }
        pos[i] = next;
        idx_map[next] = i;
    }

    int ans = 0;

#ifdef DEBUG
    printf("%d %d\n", cycle_start, cycle_end);
#endif
    if(changes < cycle_end) {
        ans = pos[changes];
    } else {
        changes -= cycle_start;
        ans = pos[cycle_start+changes%(cycle_end-cycle_start)];
    }
    printf("%d\n", ans);
    return 0;
}
