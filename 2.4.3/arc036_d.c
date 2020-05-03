#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 50

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

int get_int4(int *a1, int *a2, int *a3, int *a4) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d %d", a1, a2, a3, a4);
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
    if(is_connect(ufind, v1, v2)) return;
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

enum {
    TYPE_ADD = 1,
    TYPE_REQUEST,
    TYPE_ALL
};

struct pair {
    int v;
    int is_even;
};

#define NUM_MAX 100000
#define QUERY_MAX 100000

int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    char ans[QUERY_MAX];
    int aidx = 0;
    int i;
    struct ufind *ufind = create_ufind(num*2);
    for(i = 0; i < queries; i++) {
        int type, v1, v2, z;
        get_int4(&type, &v1, &v2, &z);
        v1--; v2--;
        switch(type) {
            case TYPE_ADD:
                if(z%2) { // ODD
                    unify(ufind, v1*2, v2*2+1);
                    unify(ufind, v1*2+1, v2*2);
                } else {
                    unify(ufind, v1*2, v2*2);
                    unify(ufind, v1*2+1, v2*2+1);
                }
                break;
            case TYPE_REQUEST:
                ans[aidx++] = is_connect(ufind, v1*2, v2*2);
            default:
                break;
        }
    }
    for(i = 0; i < aidx; i++) {
        printf("%s\n", ans[i] ? "YES" : "NO");
    }
    return 0;
}
