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

#define HASH_SIZE 65536

struct list {
    int num;
    int val;
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

struct list* find(struct list *htable, int num) {
    struct list *head = &htable[get_key(num)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->num == num) {
            return elem;
        }
    }
    return NULL;
}

int find_val(struct list *htable, int num) {
    struct list *elem = find(htable, num);
    return (elem) ? elem->val : 0;
}

void add_elem(struct list *htable, int num) {
    struct list *elem = find(htable, num);
    if(elem) {
        elem->val++;
        return;
    }
    elem = malloc(sizeof(struct list));
    struct list *head = &htable[get_key(num)];
    elem->next = head->next;
    elem->num = num;
    elem->val = 1;
    head->next = elem;
}

void put_elem(struct list *htable, int num) {
    struct list *elem = find(htable, num);
    if(!elem) return;
    if(elem->val) elem->val--;
    return;
}

#define NUM_MAX 100000
#define QUERY_MAX 100000
int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);
    int qs = get_int();
    static int queries[QUERY_MAX];
    fget_array(queries, qs);

    // hashmap
    struct list *htable = create_htable();
    int i;
    for(i = 0; i < num; i++) {
        add_elem(htable, arr[i]);
    }

    int ans = 0;
    for(i = 0; i < qs; i++) {
        ans += (find_val(htable, queries[i]) > 0);
    }
    printf("%d\n", ans);
    return 0;
}
