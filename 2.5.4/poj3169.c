#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

struct edge {
    int src;
    int dst;
    int distance;
};

#define NUM_MAX 1000
#define EDGE_MAX 20000

#define INF 0x7f7f7f7f

int main(void) {
    int num, sn, ss;
    get_int3(&num, &sn, &ss);
    static struct edge edges[EDGE_MAX];
    int eidx = 0;

    int i, j;
    for(i = 0; i < sn; i++) {
        int src, dst, dist;
        get_int3(&src, &dst, &dist);
        src--; dst--;
        edges[eidx++] = (struct edge){src, dst, dist};
    }

    for(i = 1; i < num; i++) {
        edges[eidx++] = (struct edge){i, i-1, 0};
    }
    for(i = 0; i < ss; i++) {
        int src, dst, dist;
        get_int3(&src, &dst, &dist);
        src--; dst--;
        edges[eidx++] = (struct edge){dst, src, -dist};
    }

    static int dist[NUM_MAX];
    memset(dist, 0x7f, sizeof(int)*NUM_MAX);
    dist[0] = 0;
    int goal = num-1;
    // bellman ford
    for(i = 0; i < num; i++) {
        for(j = 0; j < eidx; j++) {
            struct edge e = edges[j];
            if(dist[e.src] == INF) continue;
            int new = dist[e.src] + e.distance;
            if(dist[e.dst] > new) {
                dist[e.dst] = new;
            }
        }
    }

    static char is_neg[NUM_MAX];
    // check negative circuit
    for(i = 0; i < num; i++) {
        for(j = 0; j < eidx; j++) {
            struct edge e = edges[j];
            if(dist[e.src] == INF) continue;
            int new = dist[e.src] + e.distance;
            if(dist[e.dst] > new) {
                dist[e.dst] = new;
                is_neg[e.dst] = 1;
            }
            if(is_neg[e.src]) {
                is_neg[e.dst] = 1;
            }
        }
    }
    if(is_neg[goal]) {
        printf("-1\n");
    } else if (dist[goal] == INF) {
        printf("-2\n");
    } else {
        printf("%d\n", dist[goal]);
    }
    return 0;
}
