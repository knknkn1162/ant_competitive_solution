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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

// hash
#define HASH_SIZE 65536

struct list {
    int num;
    int idx;
    struct list *next;
};

struct list *create_htable(void) {
    static struct list htable[HASH_SIZE];
    int i;
    for(i = 0; i < HASH_SIZE; i++) {
        htable[i].next = &htable[i];
    }
    return htable;
}

int get_key(int num) {
    return num & (HASH_SIZE-1);
}

int find_idx(struct list *htable, int num) {
    struct list *head = &htable[get_key(num)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->num == num) {
            return elem->idx;
        }
    }
    return -1;
}

void add_elem(struct list *htable, int num, int idx) {
    struct list *elem = malloc(sizeof(struct list));
    struct list *head = &htable[get_key(num)];
    elem->next = head->next;
    elem->num = num;
    elem->idx = idx;
    head->next = elem;
}
#define NUM_MAX 100000
#define QUERY_MAX 50000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int compress(int *arr, int size, int *unzip) {
    static int sorted[NUM_MAX];
    memcpy(sorted, arr, size*sizeof(int));
    qsort(sorted, size, sizeof(int), asc);
    struct list *htable = create_htable();
    // 0-indexed
    int idx = 0;
    int i;
    int prev = -1;
    for(i = 0; i < size; i++) {
        int cur = sorted[i];
        if(prev == cur) continue;
        add_elem(htable, cur, idx);
        unzip[idx] = cur;
        idx++;
        prev = cur;
    }

    // transform in-place
    for(i = 0; i < size; i++) {
        arr[i] = find_idx(htable, arr[i]);
    }
    return idx;
}

int lower_bound(int *arr, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    static int unzip[NUM_MAX];
    int size = compress(arr, num, unzip);

    int qs = get_int();
    static int queries[NUM_MAX];
    fget_array(queries, qs);

    int i;
    int ans = 0;
    for(i = 0; i < qs; i++) {
        int q = queries[i];
        int idx = lower_bound(unzip, size, q);
        if(idx == size) continue;
        ans += (unzip[idx] == q);
    }
    printf("%d\n", ans);
    return 0;
}
