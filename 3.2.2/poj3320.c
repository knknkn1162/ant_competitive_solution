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


struct arr_idx {
    int idx;
    int val;
};

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(struct arr_idx *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }
    return 0;
}

#define NUM_MAX 1000000

int asc_by_val(const void *a1, const void  *a2) {
    struct arr_idx *aa1 = (struct arr_idx*)a1;
    struct arr_idx *aa2 = (struct arr_idx*)a2;
    return aa1->val - aa2->val;
}

int asc_by_idx(const void *a1, const void  *a2) {
    struct arr_idx *aa1 = (struct arr_idx*)a1;
    struct arr_idx *aa2 = (struct arr_idx*)a2;
    return aa1->idx - aa2->idx;
}

int main(void) {
    int num = get_int();
    struct arr_idx arr[NUM_MAX];

    fget_array(arr, num);
    qsort(arr, num, sizeof(struct arr_idx), asc_by_val);
    int cur = -1;
    int kinds = 0;
    int i;
    for(i = 0; i < num; i++) {
        if(cur != arr[i].val) { kinds++; cur = arr[i].val; }
        arr[i].val = kinds;
    }
    qsort(arr, num, sizeof(struct arr_idx), asc_by_idx);
#ifdef DEBUG
    printf("%d\n", kinds);
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i].val);
    }
    putchar('\n');
#endif

    static int map[NUM_MAX+1];
    int ans = NUM_MAX+1;
    int cnt = 0;
    int left;
    int right = 0;
    cur = -1;
    for(left = 0; left < num; left++) {
        for(; right < num; right++) {
            if(cnt == kinds) break;
            if(!map[arr[right].val]) cnt++;
            map[arr[right].val]++;
        }
#ifdef DEBUG
        printf("[%d, %d)\n", left, right);
#endif
        if(cnt == kinds) ans = min(ans, right-left);
        map[arr[left].val]--;
        if(!map[arr[left].val]) cnt--;
        if(left==right) right++;
    }
    printf("%d\n", ans);
    return 0;
}
