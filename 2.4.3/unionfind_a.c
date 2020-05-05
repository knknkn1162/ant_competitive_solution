#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define BUF_SIZE 30
 
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
 
enum query {
    QUERY_CONNECT,
    QUERY_JUDGE,
    QUERY_ALL,
};
 
#define VERTEX_MAX 100000
#define QUERY_MAX 200000
 
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
    int vs, qs;
    get_int2(&vs, &qs);
    int i;
    struct ufind *ufind = create_ufind(vs);
    static int ans[QUERY_MAX];
    int ans_idx = 0;
    // init union find
    for(i = 0; i < qs; i++) {
        int type, v1, v2;
        get_int3(&type, &v1, &v2);
        switch(type) {
            case QUERY_CONNECT:
                unite(ufind, v1, v2);
                break;
            case QUERY_JUDGE:
                ans[ans_idx++] = is_connect(ufind, v1, v2);
                break;
            default:
                break;
        }
    }
 
    for(i = 0; i < ans_idx; i++) {
        printf("%s\n", ans[i] ? "Yes" : "No");
    }
    return 0;
}
