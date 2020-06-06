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

#define VERTEX_MAX 100
static char graph[VERTEX_MAX][VERTEX_MAX];
static char checked[VERTEX_MAX];

int is_tree(int node, int parent) {
#ifdef DEBUG
    printf("is_tree(%d, %d)\n", node, parent);
#endif
    int flag = 1;
    checked[node] = 1;
    int i;
    for(i = 0; i < VERTEX_MAX; i++) {
        if(!graph[node][i]) continue;
        if(i == parent) continue;
        if(checked[i]) {
            flag = 0;
            continue;
        }
        flag &= is_tree(i, node);
    }
    return flag;
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);

    int i;
    for(i = 0; i < es; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        graph[v1][v2] = graph[v2][v1] = 1;
    }

    int cnt = 0;
    for(i = 0; i < vs; i++) {
        if(!checked[i]) cnt += is_tree(i, -1);
    }
    printf("%d\n", cnt);
    return 0;
}
