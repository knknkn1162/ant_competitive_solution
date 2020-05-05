#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30
#define DIVISOR 1000000007

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

enum query_type {
    QUERY_RELATE,
    QUERY_DIFF,
};

struct wufind {
    int parent;
    int depth;
    int weight;
};

#define VERTEX_MAX 100000

struct wufind *create_wufind(int vs) {
    static struct wufind wu[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        wu[i].parent = i;
    }
    return wu;
}

int find_root(struct wufind *wufind, int v1) {
    struct wufind *elem = &wufind[v1];
    int base = v1;
    if(base == elem->parent) {
        return base;
    } else {
        int root = find_root(wufind, elem->parent);
        struct wufind *par = &wufind[elem->parent];
        elem->weight += par->weight;
        elem->parent = root;
        return root;
    }
}

int is_connect(struct wufind *wufind, int v1, int v2) {
    int bv1 = find_root(wufind, v1);
    int bv2 = find_root(wufind, v2);
    return bv1 == bv2;
}

void relate(struct wufind *wufind, int v1, int v2, int diff) {
    int bv1 = find_root(wufind, v1); int w1 = wufind[v1].weight;
    int bv2 = find_root(wufind, v2); int w2 = wufind[v2].weight;
    struct wufind *root1 = &wufind[bv1];
    struct wufind *root2 = &wufind[bv2];
    int neww = w1 + diff - w2; // 2->1
    if(root1->depth >= root2->depth) {
        if(root1->depth == root2->depth) root1->depth++;
        root2->depth = root1->depth;
        root2->parent = bv1;
        // 2->1(positive)
        root2->weight = neww;
    } else {
        root1->depth = root2->depth;
        root1->parent = bv2;
        // 1->2(negative)
        root1->weight = -neww;
    }
    return;
}

// v1->v2
int get_dist(struct wufind *wufind, int v1, int v2) {
    find_root(wufind, v1); find_root(wufind, v2);
    struct wufind *elem1 = &wufind[v1];
    struct wufind *elem2 = &wufind[v2];
    return elem2->weight - elem1->weight;
}

int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    int i;
    struct wufind *wufind = create_wufind(num);
    for(i = 0; i < queries; i++) {
        int type, v1, v2, diff;
        get_int4(&type, &v1, &v2, &diff);
        switch(type) {
            case QUERY_RELATE:
                // v1->v2: diff
                relate(wufind, v1, v2, diff);
                break;
            case QUERY_DIFF:
                if(!is_connect(wufind, v1, v2)) {
                    printf("?\n");
                } else {
                    int res = get_dist(wufind, v1, v2);
                    printf("%d\n", res);
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
