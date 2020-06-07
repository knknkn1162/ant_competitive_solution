#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

#define NUM_MAX 100
#define INF 0x01010101

int main(void) {
    int vs, es;
    get_int2(&vs, &es);
    static int graph[NUM_MAX][NUM_MAX];
    memset(graph, 0x01, sizeof(int)*NUM_MAX*NUM_MAX);
    int i;
    for(i = 0; i < es; i++) {
        int v1, v2, cost;
        get_int3(&v1, &v2, &cost);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        graph[v1][v2] = graph[v2][v1] = cost;
    }
    static int origin[NUM_MAX][NUM_MAX];
    memcpy(origin, graph, sizeof(int)*NUM_MAX*NUM_MAX);

    int j, k;
    // Warshall floyd
    for(k = 0; k < vs; k++) {
        for(i = 0; i < vs; i++) {
            for(j = 0; j < vs; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    int cnt = 0;
    for(i = 0; i < vs; i++) {
        for(j = i+1; j < vs; j++) {
            if(origin[i][j] == INF) continue;
            if(origin[i][j] != graph[i][j]) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
