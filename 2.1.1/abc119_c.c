#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
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


#define NUM_MAX 8

void get_arr(int *arr, int size, int pat) {
    int idx = 0;
    while(pat) {
        int type = pat&3;
        arr[idx++] = type;
        pat /= 4;
    }
}

#define INF (1e+9)

int asc(const void *a1, const void *a2) { return *(int*)a1 - *(int*)a2; }

int main(void) {
    int num, a, b, c;
    get_int4(&num, &a, &b, &c);
    int num2 = num*2;
    int base[3] = {c, b, a}; // c<b<a
    int lens[NUM_MAX];
    fget_array(lens, num);

    int pat;
    int i;
    int ans = INF;
    for(pat = 1; pat < (1<<num2); pat++) {
        int arr[NUM_MAX] = {0};
        get_arr(arr, num, pat);
        int map[3] = {0};
        int consume = 0;
        for(i = 0; i < num; i++) {
            int type = arr[i];
            if(type == 3) continue; // no use
            if(map[type]) consume += 10;
            map[type] += lens[i];
        }
        int flag = 1;
        // # of length of banboo is positive.
        for(i = 0; i < 3; i++) if(!map[i]) flag = 0;
        if(!flag) continue;
        qsort(map, 3, sizeof(int), asc);

        for(i = 0; i < 3; i++) {
            consume += abs(base[i]-map[i]);
        }
#ifdef DEBUG
        printf("%d %d %d: consume : %d\n", map[0], map[1], map[2], consume);
#endif
        ans = min(ans, consume);
    }

    printf("%d\n", ans);
    return 0;
}
