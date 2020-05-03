#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 40

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

struct edge {
    int src;
    int dst;
    int64_t npoint;
};

#define VERTEX_MAX 1000
#define EDGE_MAX 2000
#define INF (1LL<<50)

int main(void) {
    int vs, es;
    struct edge edges[EDGE_MAX];
    get_int2(&vs, &es);
    int i, j;
    for(i = 0; i < es; i++) {
        int src, dst, np;
        get_int3(&src, &dst, &np);
        // 1-indexed -> 0-indexed
        src--; dst--;
        // directed graph
        edges[i] = (struct edge){src, dst, -np};
    }

    static int64_t min_dist[VERTEX_MAX];
    for(i = 0; i < vs; i++) {
        min_dist[i] = INF;
    }
    min_dist[0] = 0;
    // bellman
    for(i = 0; i < vs; i++) {
        int flag = 0;
        for(j = 0; j < es; j++) {
            struct edge e = edges[j];
            if(min_dist[e.src] == INF) continue;
            int64_t new = min_dist[e.src] + e.npoint;
            if(min_dist[e.dst] > new) {
                flag = 1;
                min_dist[e.dst] = new;
            }
        }
        if(!flag) break;
    }

    // check negative cycle( by bellman-ford algorithm )
    static int check_negative[VERTEX_MAX]; // default=0
    for(i = 0; i < vs; i++) {
        for(j = 0; j < es; j++) {
            struct edge e = edges[j];
            if(min_dist[e.src] == INF) continue;
            int64_t new = min_dist[e.src] + e.npoint;
            if(min_dist[e.dst] > new) {
                check_negative[e.dst] = 1;
                min_dist[e.dst] = new;
            }
            if(check_negative[e.src]) {
                check_negative[e.dst] = 1;
            }
        }
    }

    if(check_negative[vs-1]) {
        printf("inf\n");
    } else {
        printf("%lld\n", -min_dist[vs-1]);
    }

    return 0;
}
