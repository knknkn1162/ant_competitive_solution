#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 0

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
#define VERTEX_MAX 100000
#define EDGE_MAX 100000

struct list {
    struct list *next;
    int dst;
};

struct list *create_graph(int vs) {
    static struct list graph[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        graph[i].next = &graph[i];
    }
    return graph;
}

struct list lpool[EDGE_MAX];
int lidx = 0;

struct list *add_list(struct list *head, int v) {
    struct list *elem = &lpool[lidx++];
    elem->dst = v;
    elem->next = head->next;
    head->next = elem;
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);

    int i;
    struct list *graph = create_graph(vs);
    for(i = 0; i < es; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        add_list(&graph[v1], v2);
        add_list(&graph[v2], v1);
    }
    return 0;
}
