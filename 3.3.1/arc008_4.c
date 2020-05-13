#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int64_t *a1, int *a2) {
  scanf("%lld %d", a1, a2);
  return 0;
}

int get_val3(int64_t *a1, double *a2, double *a3) {
  scanf("%lld %lf %lf", a1, a2, a3);
  return 0;
}

struct coff {
    double a;
    double b;
};

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

#define QUERY_MAX (1<<17)

int asc(const void *a1, const void *a2) {
    int64_t diff = *(int64_t*)a1 - *(int64_t*)a2;
    if(diff < 0) return -1;
    if(diff == 0) return 1;
    return 1;
}

int compress(int64_t *arr, int size) {
    static int64_t sorted[QUERY_MAX+1];
    int i;
    memcpy(sorted, arr, sizeof(int64_t)*size);
    qsort(sorted, size, sizeof(int64_t), asc);
    sorted[size] = -1;
#ifdef DEBUG
    for(i = 0; i <= size; i++) {
        printf(" %lld", sorted[i]);
    }
    putchar('\n');
#endif
    struct list *htable = create_htable();
    int idx = 0;
    int64_t prev = sorted[0];
    for(i = 0; i < size+1; i++) {
        if(sorted[i] == prev) continue;
        add_elem(htable, prev, idx);
        prev = sorted[i];
        idx++;
    }

    // core
    for(i = 0; i < size; i++) {
        arr[i] = find_idx(htable, arr[i]);
    }
    return idx;
}

// a2*(r*a1 + b1) + b2
struct coff composite(struct coff left, struct coff right) {
    return (struct coff){left.a * right.a, right.a*left.b + right.b};
}

void update(struct coff *seg, int num, int idx, struct coff val) {
    int node = num+idx;
    seg[node] = val;
    int parent;
    while((parent = node/2)) {
        int left = parent*2;
        int right = parent*2+1;
        seg[parent] = composite(seg[left], seg[right]);
        node = parent;
    }
    return;
}

struct pair {
    double min;
    double max;
};

void maxmin(struct pair *p, double res) {
    p->min = min(p->min, res);
    p->max = max(p->max, res);
    return;
}

int main(void) {
    struct pair ans = {1, 1};
    int64_t num;
    int queries;
    get_int2(&num, &queries);
    int i;
    static int64_t pos[QUERY_MAX];
    static struct coff coffs[QUERY_MAX];

    for(i = 0; i < queries; i++) {
        get_val3(&pos[i], &coffs[i].a, &coffs[i].b);
    }

    int _size = compress(pos, queries);
    int size = 1;
    while(_size > size) size *= 2;
#ifdef DEBUG
    printf("size: %d\n", size);
    for(i = 0; i < queries; i++) {
        printf("[%lld] => r*%lf + %lf\n", pos[i], coffs[i].a, coffs[i].b);
    }
#endif

    static struct coff seg[QUERY_MAX*2];
    for(i = 1; i < size*2; i++) {
        seg[i] = (struct coff){1, 0};
    }

    for(i = 0; i < queries; i++) {
        update(seg, size, pos[i], coffs[i]);
        double res = seg[1].a + seg[1].b;
#ifdef DEBUG
        printf("%lf + %lf\n", seg[1].a, seg[1].b);
#endif
        maxmin(&ans, res);
    }

    printf("%.7lf\n", ans.min);
    printf("%.7lf\n", ans.max);
    return 0;
}
