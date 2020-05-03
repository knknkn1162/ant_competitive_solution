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
#define VERTEX_MAX 100000

struct list {
    int dst;
    int length;
    struct list *next;
};

struct list *create_graph(int vs) {
    static struct list graph[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        graph[i].next = &graph[i];
    }
    return graph;
}

void add_list(struct list *head, int dst, int len) {
    struct list *elem = malloc(sizeof(struct list));
    elem->next = head->next;
    head->next = elem;
    elem->dst = dst;
    elem->length = len;
}

enum {
    ENUM_NONE,
    ENUM_WHITE,
    ENUM_BLACK,
};

int next_color(int color) {
    if(color == ENUM_WHITE) return ENUM_BLACK;
    if(color == ENUM_BLACK) return ENUM_WHITE;
    return ENUM_NONE;
}

static char check[VERTEX_MAX];
void dfs(struct list *graph, int this, int parent, int color) {
    struct list *head = &graph[this];
    check[this] = color;
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        int dst = elem->dst;
        if(dst == parent) continue;
        dfs(graph, dst, this, elem->length%2 ? next_color(color) : color);
    }
    return;
}

int main(void) {
    int vs = get_int();
    int es = vs - 1;
    int i;
    struct list *graph = create_graph(vs);
    for(i = 0; i < es; i++) {
        int v1, v2, len;
        get_int3(&v1, &v2, &len);
        v1--; v2--;
        add_list(&graph[v1], v2, len);
        add_list(&graph[v2], v1, len);
    }

    dfs(graph, 0, -1, ENUM_WHITE);
    for(i = 0; i < vs; i++) {
        printf("%d\n", check[i]-1);
    }
    return 0;
}
