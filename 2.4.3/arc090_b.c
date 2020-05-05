#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 50
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

struct wufind {
    int parent;
    int depth;
    int dist;
};

#define VERTEX_MAX 100000
struct wufind *create_wufind(int num) {
    static struct wufind wufind[VERTEX_MAX];
    int i;
    for(i = 0; i < num; i++) {
        wufind[i].parent = i;
    }
    return wufind;
}

int get_root(struct wufind *wu, int v) {
    int base = v;
    struct wufind *elem = &wu[v];
    if(base == elem->parent) {
        return base;
    } else {
        int root = get_root(wu, elem->parent);
        struct wufind *par = &wu[elem->parent];
        elem->dist += par->dist;
        // compression
        elem->parent = root;
        return root;
    }
} 

int get_diff(struct wufind *wufind, int v1, int v2) {
    get_root(wufind, v1);
    get_root(wufind, v2);
#ifdef DEBUG
    printf("get_diff: %d\n", wufind[v2].dist - wufind[v1].dist);
#endif
    return wufind[v2].dist - wufind[v1].dist;
}

int is_connect(struct wufind *wufind, int v1, int v2) {
    int root1 = get_root(wufind, v1);
    int root2 = get_root(wufind, v2);
#ifdef DEBUG
    printf("is_connect: v1: %d, v2: %d\n", root1, root2);
#endif
    return root1 == root2;
}

// assume that v1, v2 gets compresson done
void unite(struct wufind *wufind, int v1, int v2, int diff) {
    int root1 = wufind[v1].parent;
    int root2 = wufind[v2].parent;
    int w1 = wufind[v1].dist;
    int w2 = wufind[v2].dist;
    struct wufind *wr1 = &wufind[root1];
    struct wufind *wr2 = &wufind[root2];
    // 2->1
    int new_dist = w1 + diff - w2;
    if(wr1->depth >= wr2->depth) {
        if(wr1->depth == wr2->depth) wr1->depth++;
        // 2->1
        wr2->parent = root1;
        wr2->depth = wr1->depth;
        wr2->dist = new_dist;
    } else {
        // 1->2
        wr1->parent = root2;
        wr1->depth = wr2->depth;
        wr1->dist = -new_dist;
    }
    return;
}

#include <limits.h>
#define DIST_MAX 1000000000

int main(void) {
    int num, qs;
    get_int2(&num, &qs);
    struct wufind *wufind = create_wufind(num);

    int i;
    int flag = 1;
    for(i = 0; i < qs; i++) {
        int p1, p2, diff;
        get_int3(&p1, &p2, &diff);
        // 1-indexed -> 0-indexed
        p1--; p2--;
        if(!is_connect(wufind, p1, p2)) {
            unite(wufind, p1, p2, diff);
        } else {
            if(diff != get_diff(wufind, p1, p2)) {
                flag = 0;
                break;
            }
        }
    }
    // int mi = INT_MAX;
    // int ma = INT_MIN;
    // for(i = 1; i < num; i++) {
    //     int res = get_diff(wufind, 0, i);
    //     mi = min(mi, res);
    //     ma = max(ma, res);
    // }
    // if(ma-mi > DIST_MAX) flag = 0;
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}
