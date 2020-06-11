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

struct edge {
    int v1;
    int v2;
};

struct person {
    int idx;
    int city;
};

struct history {
    int type;
    int year;
    union {
        struct edge edge;
        struct person person;
    } u;
};

enum type {
    TYPE_EDGE,
    TYPE_PERSON,
};

#define NUM_MAX 100000
#define QUERY_MAX 200000
#define EDGE_MAX 200000

int desc_by_year(const void *a1, const void *a2) {
    struct history *e1 = (struct history*)a1;
    struct history *e2 = (struct history*)a2;
    if(e1->year == e2->year) {
        // PERSON first
        return e2->type - e1->type;
    }
    return e2->year - e1->year;
}

struct ufind {
    int parent;
    int depth;
    int count;
};

#define VERTEX_MAX 100000
struct ufind *create_ufind(int vs) {
    static struct ufind ufind[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        ufind[i].parent = i;
        ufind[i].depth = 0;
        ufind[i].count = 1;
    }
    return ufind;
}

int find_root(struct ufind *ufind, int v) {
    struct ufind *elem = &ufind[v];
    int base = v;
    if(base == elem->parent) {
        return base;
    } else {
        int root = find_root(ufind, elem->parent);
        elem->parent = root;
        return root;
    }
}

int is_connect(struct ufind *ufind, int v1, int v2) {
    int bv1 = find_root(ufind, v1);
    int bv2 = find_root(ufind, v2);
    return bv1 == bv2;
}

void unite(struct ufind *ufind, int v1, int v2) {
    int bv1 = find_root(ufind, v1);
    int bv2 = find_root(ufind, v2);
    struct ufind *uv1 = &ufind[bv1];
    struct ufind *uv2 = &ufind[bv2];
    if(uv1->depth >= uv2->depth) {
        if(uv1->depth == uv2->depth) uv1->depth++;
        uv2->depth = uv1->depth;
        uv2->parent = uv1->parent;
        uv1->count += uv2->count;
    } else {
        uv1->depth = uv2->depth;
        uv1->parent = uv2->parent;
        uv2->count += uv1->count;
    }
    return;
}

int count(struct ufind *ufind, int city) {
    int root = find_root(ufind, city);
    struct ufind *elem = &ufind[root];
    return elem->count;
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);
    static struct history his[EDGE_MAX+QUERY_MAX];
    int hidx = 0;
    int i;
    for(i = 0; i < es; i++) {
        int v1, v2;
        int year;
        get_int3(&v1, &v2, &year);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        struct edge e = (struct edge){v1, v2};
        his[hidx++] = (struct history){
            .type = TYPE_EDGE, .year = year, .u={.edge=e}
        };
    }
    int qs = get_int();
    for(i = 0; i < qs; i++) {
        int city, year;
        get_int2(&city, &year);
        // 1-indexed -> 0-indexed
        city--;
        struct person p = (struct person){i, city};
        his[hidx++] = (struct history){
            .type = TYPE_PERSON, .year = year, .u={.person=p}
        };
    }
    qsort(his, hidx, sizeof(struct history), desc_by_year);

    struct ufind *ufind = create_ufind(vs);
    static int ans[QUERY_MAX];
    i = 0;
    for(i = 0; i < hidx; i++) {
        struct history h = his[i];
        switch(h.type) {
            case TYPE_EDGE:
                {
                    struct edge e = h.u.edge;
                    if(is_connect(ufind, e.v1, e.v2)) continue;
                    unite(ufind, e.v1, e.v2);
                }
                break;
            case TYPE_PERSON:
                {
                    struct person p = h.u.person;
                    ans[p.idx] = count(ufind, p.city);
                }
                break;
            default:
                break;
        }
    }
    for(i = 0; i < qs; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
