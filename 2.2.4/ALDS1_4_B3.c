#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

struct thing {
    int type;
    int val;
};

enum type {
    TYPE_ELEM,
    TYPE_QUERY,
};


// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(struct thing *arr, int type, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int val;
        scanf("%d", &val);
        arr[i] = (struct thing){.type = type, .val = val};
    }
    return 0;
}

int asc_by_val(const void *a1, const void *a2) {
    struct thing *t1 = (struct thing*)a1;
    struct thing *t2 = (struct thing*)a2;
    if(t1->val == t2->val) {
        return t1->type - t2->type;
    }
    return t1->val - t2->val;
}

#define NUM_MAX 100000
#define QUERY_MAX 100000
int main(void) {
    int num = get_int();
    static struct thing arr[NUM_MAX+QUERY_MAX];
    fget_array(arr, TYPE_ELEM, num);
    int qs = get_int();
    fget_array(&arr[num], TYPE_QUERY, qs);

    int size = num + qs;
    qsort(arr, size, sizeof(struct thing), asc_by_val);

    int i;
    int val = 0;
    int ans = 0;
    for(i = 0; i < size; i++) {
        struct thing t = arr[i];
        switch(t.type) {
            case TYPE_ELEM:
                val = t.val;
                break;
            case TYPE_QUERY:
                ans += (val == t.val);
                // reset
                val = 0;
                break;
            default:
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
