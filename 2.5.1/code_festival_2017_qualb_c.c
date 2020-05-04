#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

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
#define VERTEX_MAX 100000
#define EDGE_MAX 100000

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

enum {
    ENUM_EVEN,
    ENUM_ODD
};

int main(void) {
    int vs, es;
    get_int2(&vs, &es);

    int i;
    struct ufind *ufind = create_ufind(vs*2);
    for(i = 0; i < es; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        unify(ufind, v1*2+ENUM_EVEN, v2*2+ENUM_ODD);
        unify(ufind, v1*2+ENUM_ODD, v2*2+ENUM_EVEN);
    }

    int both = 0;
    int even = 0;
    int odd = 0;
    for(i = 0; i < vs; i++) {
        int flag1 = is_connect(ufind, 0, i*2+ENUM_EVEN);
        int flag2 = is_connect(ufind, 0, i*2+ENUM_ODD);
        if(flag1 && flag2) {
            both++;
        } else if(flag1 && !flag2) {
            even++;
        } else {
            odd++;
        }
    }
#ifdef DEBUG
    printf("result: %d, %d %d\n", both, even, odd);
#endif
    uint64_t ans = (uint64_t)even*odd + (uint64_t)both*(both-1)/2;
    ans = ans - (uint64_t)es;
    printf("%llu\n", ans);
    return 0;
}
