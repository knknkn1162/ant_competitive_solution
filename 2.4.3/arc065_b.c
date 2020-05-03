#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 40

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d", a1, a2, a3);
#else
#error
#endif
  return 0;
}

struct ufind {
    int parent;
    int depth;
};

struct ufind *create_ufind(int vs) {
    struct ufind *ufind = malloc(vs * sizeof(struct ufind));
    int i;
    for(i = 0; i < vs; i++) {
        ufind[i].parent = i;
        ufind[i].depth = 0;
    }
    return ufind;
}

int find_root(struct ufind *ufind, int v) {
    struct ufind *elem = &ufind[v];
    int base = v;
    while(base != elem->parent) {
        base = elem->parent;
        elem = &ufind[base];
    }
    return base;
}

int is_connect(struct ufind *ufind, int v1, int v2) {
    int bv1 = find_root(ufind, v1);
    int bv2 = find_root(ufind, v2);
    return bv1 == bv2;
}

void unify(struct ufind *ufind, int v1, int v2) {
    int bv1 = find_root(ufind, v1);
    int bv2 = find_root(ufind, v2);
    struct ufind *uv1 = &ufind[bv1];
    struct ufind *uv2 = &ufind[bv2];
    if(uv1->depth >= uv2->depth) {
        if(uv1->depth == uv2->depth) uv1->depth++;
        uv2->depth = uv1->depth;
        uv2->parent = uv1->parent;
    } else {
        uv1->depth = uv2->depth;
        uv1->parent = uv2->parent;
    }
    return;
}

#define NUM_MAX 200000

struct pair {
    int p1;
    int p2;
};

#define HTABLE_SIZE 65536
struct list {
    struct pair key;
    struct list* next;
    int count;
};

struct list *create_htable(void) {
    static struct list htable[HTABLE_SIZE];
    int i;
    for(i = 0; i < HTABLE_SIZE; i++) {
        htable[i].next = &htable[i];
    }
    return htable;
}

int get_key(struct pair p) {
    return (p.p1 | p.p2)&(HTABLE_SIZE-1);
}

int is_equal(struct pair pa, struct pair pb) {
    return pa.p1 == pb.p1 && pa.p2 == pb.p2;
}

void add_htable(struct list *htable, struct pair p) {
    int key = get_key(p);
    struct list *elem;
    struct list *head = &htable[key];
    for(elem = head->next; elem != head; elem = elem->next) {
        if(is_equal(p, elem->key)) {
            elem->count++;
            return;
        }
    }
    // if not exist, add
    elem = malloc(sizeof(struct list));
    elem->count = 1;
    elem->next = head->next;
    elem->key = p;
    head->next = elem;
}

int find_count(struct list *htable, struct pair p) {
    int key = get_key(p);
    struct list *elem;
    struct list *head = &htable[key];
    for(elem = head->next; elem != head; elem = elem->next) {
        if(is_equal(p, elem->key)) {
            return elem->count;
        }
    }
    return 1;
}

int main(void) {
    int vs, roads, rails;
    get_int3(&vs, &roads, &rails);

    struct ufind *road_ufind = create_ufind(vs);
    struct ufind *rail_ufind = create_ufind(vs);

    int i;
    for(i = 0; i < roads; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        if(!is_connect(road_ufind, v1, v2)) {
            unify(road_ufind, v1, v2);
        }
    }

    for(i = 0; i < rails; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        if(!is_connect(rail_ufind, v1, v2)) {
            unify(rail_ufind, v1, v2);
        }
    }

    // put result into hash table for speeding up
    static struct pair cache[NUM_MAX];
    struct list *htable = create_htable();
    for(i = 0; i < vs; i++) {
        struct pair p = {
            find_root(road_ufind, i),
            find_root(rail_ufind, i)
        };

        cache[i] = p;
        add_htable(htable, p);
#ifdef DEBUG
        printf("%d: %d %d", i, p.p1, p.p2);
#endif
    }

    for(i = 0; i < vs; i++) {
        struct pair p = cache[i];
        printf("%d%c", find_count(htable, p), i==(vs-1) ? '\n' : ' ');
    }
    return 0;
}
