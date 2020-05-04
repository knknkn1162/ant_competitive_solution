#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 40
#define DIVISOR 1000000007

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
    struct list *next;
    int dst;
    int length;
};

struct list *create_graph(int vs) {
    static struct list graph[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        graph[i].next = &graph[i];
    }
    return graph;
}

void add_list(struct list *head, int dst, int length) {
    struct list *elem = malloc(sizeof(struct list));
    elem->next = head->next;
    elem->dst = dst;
    elem->length = length;
    head->next = elem;
}

void dfs(struct list *graph, int this, int parent, int length, uint64_t *out) {
    struct list *head = &graph[this];
    struct list *elem;
    if(parent != -1) {
        out[this] = out[parent] + length;
    }
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->dst == parent) continue;
        dfs(graph, elem->dst, this, elem->length, out);
    }
    return;
}

#define QUERY_MAX 100000

int main(void) {
    int vs = get_int();
    int es = vs - 1;
    static uint64_t ans[QUERY_MAX];
    static int aidx = 0;
    struct list *graph = create_graph(vs);

    int i;
    for(i = 0; i < es; i++) {
        int v1, v2, length;
        get_int3(&v1, &v2, &length);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        add_list(&graph[v1], v2, length);
        add_list(&graph[v2], v1, length);
    }

    int qs; int root;
    get_int2(&qs, &root);
    // 1-indexed -> 0-indexed
    root--;

    static uint64_t dist[VERTEX_MAX];
    dfs(graph, root, -1, 0, dist);

    for(i = 0; i < qs; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        // 0-indexed -> 1-indexed
        v1--; v2--;
        ans[aidx++] = dist[v1] + dist[v2];
    }

    for(i = 0; i < aidx; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
