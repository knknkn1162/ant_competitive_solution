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
    int weight;
};

#define EDGE_MAX 2000
#define VERTEX_MAX 1000
#define INF ((int64_t)0x01010101)

int main(void) {
    int vs, es, start;
    get_int3(&vs, &es, &start);
    struct edge edges[EDGE_MAX];

    int i, j;
    for(i = 0; i < es; i++) {
        int src, dst, w;
        get_int3(&src, &dst, &w);
        edges[i] = (struct edge){src, dst, w};
    }

    int min_dist[VERTEX_MAX];
    memset(min_dist, 0x01, sizeof(int)*VERTEX_MAX);
    min_dist[start] = 0;
    for(j = 0; j < vs; j++) {
        int flag = 0;
        for(i = 0; i < es; i++) {
            struct edge e = edges[i];
            if(min_dist[e.src] == INF) continue;
            int new = min_dist[e.src] + e.weight;
            if(min_dist[e.dst] > new) {
                min_dist[e.dst] = new;
                flag = 1;
            }
        }
        // there is negative loop
        if(j == (vs-1) && flag) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for(i = 0; i < vs; i++) {
        if(min_dist[i] >= INF) {
            printf("INF\n");
        } else {
            printf("%d\n", min_dist[i]);
        }
    }
    return 0;
}
