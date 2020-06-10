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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
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

struct range {
    int start;
    int end;
};

struct work {
    struct range r;
    int pos;
};

int desc_by_pos(const void *a1, const void *a2) {
    struct work *w1 = (struct work*)a1;
    struct work *w2 = (struct work*)a2;
    return w2->pos - w1->pos;
}

#define NUM_MAX 200000
#define ROOT_NODE 1
#define QUERY_MAX 200000

#define NUM2_MAX (1<<18)

int upper_bound(int *arr, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int compress(struct work *works, int size, int *unzip) {
    static int sorted[NUM_MAX*2+50];
    int i;
    for(i = 0; i < size; i++) {
        sorted[i] = works[i].r.start;
    }
    for(i = 0; i < size; i++) {
        sorted[i+size] = works[i].r.end;
    }
    qsort(sorted, size*2, sizeof(int), asc);
    struct list *htable = create_htable();
    int prev = sorted[0]-1;
    // 0-indexed
    int idx = 0;
    for(i = 0; i < size*2; i++) {
        int cur = sorted[i];
        if(prev == cur) continue;
        add_elem(htable, cur, idx);
        unzip[idx] = cur;
        idx++;
        prev = cur;
    }

    // transform in place
    for(i = 0; i < size; i++) {
        struct range r = works[i].r;
        works[i].r.start = find_idx(htable, r.start);
        works[i].r.end = find_idx(htable, r.end);
    }
    return idx;
}


// segtree
int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range this, struct range box) {
    return box.start <= this.start && this.end <= box.end;
}

void update(int *seg, struct range r, int val, int node, struct range nr) {
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        // update
        seg[node] = val;
        return;
    }
    struct range left = (struct range){nr.start, (nr.start+nr.end)/2};
    struct range right = (struct range){(nr.start+nr.end)/2, nr.end};
    update(seg, r, val, node*2, left);
    update(seg, r, val, node*2+1, right);
    return;
}

#define INF 0x7f7f7f7f

int get_val(int *seg, int size2, int idx) {
    int node = size2 + idx;
    int ans = INF;
    while(node) {
        ans = min(seg[node], ans);
        node /= 2;
    }
    return ans;
}

int main(void) {
    int num, qs;
    get_int2(&num, &qs);
    static struct work works[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        int start, end, pos;
        get_int3(&start, &end, &pos);
        works[i] = (struct work){
            {max(start-pos, 0), max(0, end-pos)}, pos
        };
    }
    static int unzip[NUM_MAX*2+50];
    // 0-indexed
    int size = compress(works, num, unzip);
#ifdef DEBUG
    for(i = 0; i < size; i++) {
        printf("%d[size: %d]: %d\n", i, size, unzip[i]);
    }
#endif

    int size2 = 1;
    // power of 2
    while(size > size2) size2 *= 2;
    qsort(works, num, sizeof(struct work), desc_by_pos);
    static int seg[NUM2_MAX*2];
    memset(seg, 0x7f, sizeof(int)*(NUM2_MAX*2));

    struct range whole = {0, size2};
    for(i = 0; i < num; i++) {
        struct work w = works[i];
#ifdef DEBUG
        printf("%d, %d to val: %d\n", w.r.start, w.r.end, w.pos);
#endif
        if(w.r.start == 0 && w.r.end == 0) continue; // no longer need
        update(seg, w.r, w.pos, ROOT_NODE, whole);
    }

    static int ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < qs; i++) {
        int q = get_int();
        int idx = upper_bound(unzip, size, q);
#ifdef DEBUG
        printf("%d -> idx: %d[ size: %d ]\n", q, idx, size2);
#endif
        if(idx == -1) {
            ans[aidx++] = INF;
        } else {
            ans[aidx++] = get_val(seg, size2, idx);
        }
    }

    for(i = 0; i < qs; i++) {
        printf("%d\n", ans[i] == INF ? -1 : ans[i]);
    }
    return 0;
}
