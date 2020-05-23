#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

struct ufind {
    int parent;
    int depth;
};

#define VERTEX_MAX 100000
struct ufind *create_ufind(int vs) {
    static struct ufind ufind[VERTEX_MAX*2];
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
    } else {
        uv1->depth = uv2->depth;
        uv1->parent = uv2->parent;
    }
    return;
}

int main(void) {
    int num, cs;
    get_int2(&num, &cs);
    struct ufind *ufind = create_ufind(num*2);

    int i;
    for(i = 0; i < cs; i++) {
        int v1, v2, coff;
        get_int3(&v1, &v2, &coff);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        // even
        if(coff%2 == 0) {
            unite(ufind, v1*2, v2*2);
            unite(ufind, v1*2+1, v2*2+1);
        } else {
            unite(ufind, v1*2, v2*2+1);
            unite(ufind, v1*2+1, v2*2);
        }
    }

    int ans = 0;
    static int root_map[VERTEX_MAX*2];
    for(i = 0; i < num*2; i++) {
        int root = find_root(ufind, i);
        if(!root_map[root]) ans++;
        root_map[root]++;
    }
    printf("%d\n", ans/2);
    return 0;
}
