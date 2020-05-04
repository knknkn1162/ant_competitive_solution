#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 40

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}
enum query_type {
    QUERY_SAME,
    QUERY_EAT,
};

enum animal {
    ANIMAL_A,
    ANIMAL_B,
    ANIMAL_C,
};

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


int main(void) {
    int animals, queries;
    get_int2(&animals, &queries);

    struct ufind *ufind = create_ufind(animals*3);

    int i;

    int wrongs = 0;
    for(i = 0; i < queries; i++) {
#ifdef DEBUG
        printf("%d-1: %d\n", i, wrongs);
#endif
        int type, x, y;
        get_int3(&type, &x, &y);
        // 0-indexed -> 1-indexed
        type--; x--; y--;
        // x and y should be between ranges
        if(x < 0 || x >= animals || y < 0 || y >= animals) {
            wrongs++;
            continue;
        }
        switch(type) {
            case QUERY_SAME:
                if(x == y) break;
                // if x and y are the ones between the food chain releationship, that must be wrong!
                if(is_connect(ufind, x*3+ANIMAL_A, y*3+ANIMAL_B) ||
                    is_connect(ufind, x*3+ANIMAL_A, y*3+ANIMAL_C)) {
                    wrongs++;
                    break;
                }
                unify(ufind, x*3+ANIMAL_A, y*3+ANIMAL_A);
                unify(ufind, x*3+ANIMAL_B, y*3+ANIMAL_B);
                unify(ufind, x*3+ANIMAL_C, y*3+ANIMAL_C);
                break;
            case QUERY_EAT:
                if(x == y) { wrongs++; break; }
                // if x and y are the same type of animal OR
                // x: prey, y: predator, that must be wrong
                if(is_connect(ufind, x*3+ANIMAL_A, y*3+ANIMAL_A) ||
                    is_connect(ufind, x*3+ANIMAL_A, y*3+ANIMAL_C)) {
                    wrongs++; break;
                }
                // x: predator, y: prey
                unify(ufind, x*3+ANIMAL_A, y*3+ANIMAL_B);
                unify(ufind, x*3+ANIMAL_B, y*3+ANIMAL_C);
                unify(ufind, x*3+ANIMAL_C, y*3+ANIMAL_A);
                break;
            default: // wrong type
                wrongs++;
                break;
        }
    }
    printf("%d\n", wrongs);
    return 0;
}
