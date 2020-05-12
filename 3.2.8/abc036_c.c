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

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    static int sorted[NUM_MAX];
    memcpy(sorted, arr, sizeof(int)*num);
    qsort(sorted, num, sizeof(int), asc);
    struct list *htable = create_htable();
    int i;
    int cur = -1;
    int idx = 0;
    for(i = 0; i < num; i++) {
        if(cur == sorted[i]) continue;
        add_elem(htable, sorted[i], idx);
        idx++;
        cur = sorted[i];
    }

    for(i = 0; i < num; i++) {
        printf("%d\n", find_idx(htable, arr[i]));
    }

    return 0;
}
