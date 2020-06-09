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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

struct combi {
    int64_t val;
    int xpos;
    int ypos;
    int zpos;
};
#define NUM_MAX 1000
#define K_MAX 3000

#define HEAP_MAX (K_MAX*10)
static struct combi heap[HEAP_MAX];
static int hidx = 1;

int is_empty(void) {
    return hidx == 1;
}
int cmp(struct combi c1, struct combi c2) {
    return c1.val > c2.val;
}

void swap(struct combi *c1, struct combi *c2) {
    struct combi tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void enqueue(struct combi c) {
    int node = hidx;
    heap[hidx++] = c;
    int parent;
    while((parent = node / 2)) {
        if(cmp(heap[parent], heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
    return;
}

struct combi dequeue_max(void) {
    struct combi ans = heap[1];
    heap[1] = heap[--hidx];
    int node = 1;
    while(1) {
        int smallest = node;
        int left = node * 2;
        int right = node * 2 + 1;
        if(left < hidx && !cmp(heap[smallest], heap[left])) {
            smallest = left;
        }
        if(right < hidx && !cmp(heap[smallest], heap[right])) {
            smallest = right;
        }
        if(smallest == node) break;
        swap(&heap[smallest], &heap[node]);
        node = smallest;
    }
    return ans;
}


int dir[3][3] = {
    {1,0,0},
    {0,1,0},
    {0,0,1},
};

// sort
int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}
#define INF (1e+16)

int is_equal(struct combi na, struct combi nb) {
    return na.xpos == nb.xpos && na.ypos == nb.ypos && na.zpos == nb.zpos;
}

#define HASH_SIZE 65536
struct pos3 {
    int xpos;
    int ypos;
    int zpos;
};

struct list {
    struct pos3 num;
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

int is_pos3_equal(struct pos3 p1, struct pos3 p2) {
    return p1.xpos == p2.xpos && p1.ypos == p2.ypos && p1.zpos == p2.zpos;
}
int get_key(struct pos3 num) {
    return (num.xpos + num.ypos + num.zpos) & (HASH_SIZE-1);
}

struct list* find(struct list *htable, struct pos3 num) {
    struct list *head = &htable[get_key(num)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(is_pos3_equal(elem->num, num)) {
            return elem;
        }
    }
    return NULL;
}

int find_val(struct list *htable, struct pos3 num) {
    struct list *elem = find(htable, num);
    return (elem) ? elem->val : 0;
}

void add_elem(struct list *htable, struct pos3 num) {
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


int is_used(struct list *htable, struct pos3 num) {
    if(find_val(htable, num)) return 1;
    add_elem(htable, num);
    return 0;
}

int main(void) {
    int xs, ys, zs;
    get_int3(&xs, &ys, &zs);
    int k = get_int();

    int i;
    static int64_t xrr[NUM_MAX+1];
    static int64_t yrr[NUM_MAX+1];
    static int64_t zrr[NUM_MAX+1];
    fget_array(xrr, xs);
    fget_array(yrr, ys);
    fget_array(zrr, zs);
    xrr[xs] = yrr[ys] = zrr[zs] = -INF;
    qsort(xrr, xs, sizeof(int64_t), desc);
    qsort(yrr, ys, sizeof(int64_t), desc);
    qsort(zrr, zs, sizeof(int64_t), desc);

    // for avoiding deplicated element
    struct list *htable = create_htable();

    static int64_t ans[K_MAX+10];
    int aidx = 0;

    enqueue((struct combi){xrr[0]+yrr[0]+zrr[0], 0, 0, 0});
    while(!is_empty()) {
        if(aidx >= k) break;
        struct combi cur = dequeue_max();
#ifdef DEBUG
        printf("%d, %d, %d -> %lld\n", cur.xpos, cur.ypos, cur.zpos, cur.val);
#endif
        ans[aidx++] = cur.val;
        for(i = 0; i < 3; i++) {
            struct pos3 next = {cur.xpos+dir[i][0], cur.ypos+dir[i][1], cur.zpos+dir[i][2]};
            if(is_used(htable, next)) continue;
            int64_t nval = xrr[next.xpos] + yrr[next.ypos] + zrr[next.zpos];
            struct combi nc = {nval, next.xpos, next.ypos, next.zpos};
            enqueue(nc);
        }
    }

    for(i = 0; i < aidx; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
