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
#define NUM2_MAX (1<<17)

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

// in-place
int compress(int *arr, int num) {
    static int sorted[NUM_MAX+1];
    struct list *htable = create_htable();
    
    memcpy(sorted, arr, sizeof(int)*num);
    qsort(sorted, num, sizeof(int), asc);
    sorted[num] = -1; // guard
    int idx = 1; // 1-indexed
    int prev = sorted[0];
    int i;
    for(i = 0; i < num+1; i++) {
        if(prev == sorted[i]) continue;
        add_elem(htable, prev, idx++);
        prev = sorted[i];
    }

    for(i = 0; i < num; i++) {
        arr[i] = find_idx(htable, arr[i]);
    }
    return idx;
}

struct range {
    int start;
    int end;
};

#define ROOT_NODE 1

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

int is_contain(struct range elem, struct range box) {
    return elem.start >= box.start && elem.end <= box.end;
}

int get_max(int *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    struct range left = {nr.start, (nr.start + nr.end)/2};
    struct range right = {left.end + 1, nr.end};
    int m1 = get_max(seg, r, node*2, left);
    int m2 = get_max(seg, r, node*2+1, right);
    return max(m1, m2);
}
int get_val(int *seg, int num, int idx) {
    return seg[num+idx];
}

void update(int *seg, int num, int idx, int val) {
    int node = num + idx;
    seg[node] = val;
    while((node = node/2)) {
        seg[node] = max(seg[node*2], seg[node*2+1]);
    }
    return;
}

int main(void) {
    static int arr[NUM_MAX];
    int num = get_int();
    int i;

    fget_array(arr, num);

    int size = compress(arr, num); // max(arr)
    int size2 = 1;
    while(size > size2) size2 *= 2;
#ifdef DEBUG
    for(i = 0; i < num; i++) printf(" %d", arr[i]);
    putchar('\n');
#endif

    // maximum
    static int seg[NUM2_MAX*2];

    struct range whole = {0, size2-1};
    for(i = 0; i < num; i++) {
        int cur = arr[i];
        struct range r = {0, cur-1};
        int new = get_max(seg, r, ROOT_NODE, whole) + 1;
#ifdef DEBUG
        printf("%d: %d\n", i, new);
#endif
        // compare old vs new
        if(get_val(seg, size2, cur) < new) {
            update(seg, size2, cur, new);
        }
    }

    printf("%d\n", seg[ROOT_NODE]);
    return 0;
}
