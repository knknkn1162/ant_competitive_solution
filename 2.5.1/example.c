/*
3 3
0 1
1 2
2 0
=> No

4 4
0 1
0 3
1 2
2 3
=> Yes
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 20

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

#define VERTEX_MAX 1000

enum color {
    ENUM_NONE,
    ENUM_BLACK,
    ENUM_WHITE,
};

int next_color(int color) {
    if(color == ENUM_BLACK) return ENUM_WHITE;
    if(color == ENUM_WHITE) return ENUM_BLACK;
    return ENUM_NONE;
}

static char check[VERTEX_MAX];
static char graph[VERTEX_MAX][VERTEX_MAX];
int dfs(int node, int size, int color) {
    int i;
    check[node] = color;
    int flag = 1;
    for(i = 0; i < size; i++) {
        if(!graph[node][i]) continue;
        if(check[i]) {
            if(check[i] != next_color(color)) {
                flag = 0; break;
            } else { continue; }
        }
        flag &= dfs(i, size, next_color(color));
    }
#ifdef DEBUG
    printf("dfs(%d,%d,%d) = %d\n", node, size, color, flag);
#endif
    return flag;
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);
    int i;
    for(i = 0; i < vs; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    int ans = 1;
    for(i = 0; i < vs; i++) {
        if(!check[i]) ans &= dfs(0, vs, ENUM_BLACK);
    }
    printf("%s\n", ans ? "Yes" : "No");
}
