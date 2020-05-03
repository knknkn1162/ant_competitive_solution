#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 10

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

enum {
    ENUM_ANGEL,
    ENUM_DEVEL,
};

#define NUM_MAX 100000

struct ufind {
    int depth;
    int parent;
};

struct ufind* create_ufind(int num) {
    static struct ufind ufind[NUM_MAX*2];
    int i;
    for(i = 0; i < num; i++) {
        ufind[i].parent = i;
        ufind[i].depth = 0;
    }
    return ufind;
}

int get_root(struct ufind *ufind, int v) {
    int base = v;
    struct ufind *uv = &ufind[v];
    while(base != uv->parent) {
        base = uv->parent;
        uv = &ufind[base];
    }
    return base;
}

void unify(struct ufind *ufind, int v1, int v2) {
    int bv1 = get_root(ufind, v1);
    int bv2 = get_root(ufind, v2);
    // v1 and v2 are already connected with each other
    if(bv1 == bv2) return;
    struct ufind *uv1 = &ufind[bv1];
    struct ufind *uv2 = &ufind[bv2];
    if(uv1->depth >= uv2->depth) { // uv1 <- uv2
        if(uv1->depth == uv2->depth) { uv1->depth++;}
        uv2->depth = uv1->depth;
        uv2->parent = uv1->parent;
    } else {
        uv1->depth = uv2->depth;
        uv1->parent = uv2->parent;
    }
    return;
}

int main(void) {
    int num = get_int();
    int ans = -1;
    // angel - i
    // devel - i
    struct ufind* ufind = create_ufind(num*2);
    int i;
    for(i = 0; i < num; i++) {
        // (angel, i) - (devel, target)
        int target = get_int() - 1;
        // i <-> target
        unify(ufind, i*2+ENUM_ANGEL, target*2+ENUM_DEVEL);
        unify(ufind, i*2+ENUM_DEVEL, target*2+ENUM_ANGEL);
    }
#ifdef DEBUG
    for(i = 0; i < num; i++) {
        printf("%d: root1: %d root2: %d\n",i, get_root(ufind, i*2), get_root(ufind, i*2+1));
    }
#endif
    for(i = 0; i < num; i++) {
        // (i,ENUM_ANGEL) - (i, ENUM_DEVEL) -> it's strange!
        if(get_root(ufind, i*2+ENUM_ANGEL) == get_root(ufind, i*2+ENUM_DEVEL)) goto finish;
    }
    ans = num/2;
finish:
    printf("%d\n", ans);
    return 0;
}
