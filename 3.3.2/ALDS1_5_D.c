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

#define NUM_MAX 200000

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}
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

int compress(int *arr, int size) {
    static int sorted[NUM_MAX+1];
    struct list *htable = create_htable();
    memcpy(sorted, arr, sizeof(int)*NUM_MAX);
    qsort(sorted, size, sizeof(int), asc);
    sorted[size] = -1;
    int prev = sorted[0];
    int i;
    int idx = 0;
    for(i = 0; i < size+1; i++) {
        int cur = sorted[i];
        if(prev == cur) continue;
        add_elem(htable, prev, idx++);
        prev = cur;
    }

    for(i = 0; i < size; i++) {
        arr[i] = find_idx(htable, arr[i]);
    }
    return idx;
}

#define NUM2_MAX (1<<18)
#define ROOT_NODE 1

struct range {
    int start;
    int end;
};

void update(int *seg, int num, int val, int idx) {
    int node = num + idx;
    seg[node] = val;
    while((node = node / 2)) {
        seg[node] = seg[node*2] + seg[node*2+1];
    }
    return;
}

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

int is_contain(struct range elem, struct range box) {
    return elem.start >= box.start && elem.end <= box.end;
}

int64_t get_sum(int *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    struct range left = {nr.start, (nr.start + nr.end)/2};
    struct range right = {left.end+1, nr.end};
    int s1 = get_sum(seg, r, node*2, left);
    int s2 = get_sum(seg, r, node*2+1, right);
    return s1 + s2;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    fget_array(arr, num);

    int size = compress(arr, num);
    int size2 = 1;
    while(size > size2) size2 *= 2;

    // configure RSQ
    static int seg[NUM2_MAX*2];
    int i;
    int64_t ans = 0;
    struct range whole = {0, size2-1};
    for(i = 0; i < num; i++) {
        int a = arr[i];
        struct range r = {0, a-1};
        int cnt = get_sum(seg, r, ROOT_NODE, whole);
        ans += (a - cnt);
#ifdef DEBUG
        printf("%d: %d\n", i, a-cnt);
#endif
        // switch 1
        update(seg, size2, 1, a);
    }
    printf("%lld\n", ans);

    return 0;
}
