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

#define NUM_MAX 100000

struct pair {
    int val;
    int idx;
};

int desc_by_val(const void *a1, const void *a2) {
    struct pair *p1 = (struct pair*)a1;
    struct pair *p2 = (struct pair*)a2;
    return p2->val - p1->val;
}

int main(void) {
    int num = get_int();
    int arr[NUM_MAX];

    fget_array(arr, num);
    static struct pair odd_map[NUM_MAX+1];
    int i, j;
    for(i = 0; i <= NUM_MAX; i++) odd_map[i].idx = i;
    static struct pair even_map[NUM_MAX+1];
    for(i = 0; i <= NUM_MAX; i++) even_map[i].idx = i;

    // even
    for(i = 0; i < num; i+=2) {
        even_map[arr[i]].val++;
    }
    for(i = 1; i < num; i+=2) {
        odd_map[arr[i]].val++;
    }

    // num >= 2
    qsort(odd_map, NUM_MAX+1, sizeof(struct pair), desc_by_val);
    qsort(even_map, NUM_MAX+1, sizeof(struct pair), desc_by_val);

    
    int ans = 0;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            if(odd_map[i].idx == even_map[j].idx) continue;
            ans = max(ans, odd_map[i].val + even_map[j].val);
        }
    }

    printf("%d\n", num-ans);
    return 0;
}
