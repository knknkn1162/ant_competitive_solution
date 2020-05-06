#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  return scanf("%d %d", a1, a2);
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  return scanf("%d %d %d %d", a1, a2, a3, a4);
}

struct edge {
    int v1;
    int v2;
    int cost;
    int time;
    double diff;
};

int desc_by_diff(const void *a1, const void *a2) {
    struct edge *ea1 = (struct edge*)a1;
    struct edge *ea2 = (struct edge*)a2;
    if(ea1->diff < ea2->diff) {
        return 1;
    } else {
        return -1;
    }
}

#define VERTEX_MAX 10000
#define EDGE_MAX 10000
#define COST_MAX 1000000
#define LOOP_MAX 300

struct ufind {
    int parent;
    int depth;
};

struct ufind *create_ufind(int vs) {
    static struct ufind ufind[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        ufind[i] = (struct ufind){
            .parent = i,
            .depth = 0,
        };
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

int judge(struct edge *edges, int es, int vs, double key) {
    int i;
    for(i = 0; i < es; i++) {
        // is profitable?
        edges[i].diff = (double)edges[i].time * key - (double)edges[i].cost;
    }
    qsort(edges, es, sizeof(struct edge), desc_by_diff);
#ifdef DEBUG
    printf("key: %lf ->", key);
    for(i = 0; i < es; i++) {
        printf("%d:%f ", edges[i].time*edges[i].cost, edges[i].diff);
    }
    putchar('\n');
#endif
    double ans = 0;
    int flag = 0;
    int cnt = 0;
    struct ufind *ufind = create_ufind(vs);
    for(i = 0; i < es; i++) {
        struct edge e = edges[i];
        double profit = max(e.diff, 0);
        if(!is_connect(ufind, e.v1, e.v2)) {
            unite(ufind, e.v1, e.v2);
            // must connect even if e.diff is negative
            profit = e.diff;
            cnt++;
        }
        ans += profit;
        // if non-profitable, flag = 0;
        if(ans < 0) { break; }
        if(cnt == vs-1) { flag = 1; break; }
    }
    return flag;
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);
    int i;

    static struct edge edges[EDGE_MAX];

    for(i = 0; i < es; i++) {
        int v1, v2, cost, time;
        get_int4(&v1, &v2, &cost, &time);
        edges[i] = (struct edge){v1, v2, cost, time, 0};
    }

    double low = -1;
    double high = COST_MAX+1;
    int count = LOOP_MAX;
    while(count--) {
        double mid = (low + high)/2;
        // lower bound
        if(judge(edges, es, vs, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.3lf\n", high);
    return 0;
}
