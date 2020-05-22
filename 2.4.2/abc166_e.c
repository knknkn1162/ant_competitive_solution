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

#define HASH_SIZE 65536

struct list {
    int val;
    int cnt;
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

int get_key(int val) {
    return val & (HASH_SIZE-1);
}

struct list* find(struct list *htable, int val) {
    struct list *head = &htable[get_key(val)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->val == val) {
            return elem;
        }
    }
    return NULL;
}

void add_elem(struct list *htable, int val) {
    struct list *elem = find(htable, val);
    struct list *head = &htable[get_key(val)];
    if(!elem) {
        // newly created
        elem = malloc(sizeof(struct list));
        elem->next = head->next;
        elem->val = val;
        elem->cnt = 0;
        head->next = elem;
    }
    elem->cnt++;
}

void put_elem(struct list *htable, int val) {
    struct list *elem = find(htable, val);
    // no way!!
    if(!elem) return;
    elem->cnt--;
}

#define NUM_MAX 200000

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    static int diff[NUM_MAX];

    fget_array(arr, num);
    int i;
    struct list *htable = create_htable();
    // a2 - h2 = h1 + a1 s.t. a1 < a2
    for(i = 0; i < num; i++) {
        // order - height
        diff[i] = (i+1) - arr[i];
        add_elem(htable, diff[i]);
    }

    int64_t ans = 0;
    for(i = 0; i < num; i++) {
        int sum = arr[i] + (i+1);
        put_elem(htable, diff[i]);
        // find within [i+1, num)
        struct list *elem = find(htable, sum);
        if(elem) ans += elem->cnt;
    }
    printf("%lld\n", ans);
}
