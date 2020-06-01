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

struct pair {
    int val;
    int idx;
};

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(struct pair *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }
    return 0;
}

#define NUM_MAX 200000

int asc(const void *a1, const void *a2) {
    struct pair *p1 = (struct pair*)a1;
    struct pair *p2 = (struct pair*)a2;
    return p1->val - p2->val;
}

int main(void) {
    int num = get_int();
    static struct pair arr[NUM_MAX];
    fget_array(arr, num);

    qsort(arr, num, sizeof(struct pair), asc);
    int i;
    int ans[NUM_MAX];
    for(i = 0; i < num/2; i++) {
        struct pair p = arr[i];
        ans[p.idx] = arr[num/2].val;
    }
    for(i = num/2; i < num; i++) {
        struct pair p = arr[i];
        ans[p.idx] = arr[num/2 - 1].val;
    }

    for(i = 0; i < num; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
