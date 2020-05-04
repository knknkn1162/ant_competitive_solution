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

struct list {
    struct list *next;
    int dst;
};

#define VERTEX_MAX 100000
#define DIVISOR 1000000007

struct list *create_graph(int vs) {
    static struct list graph[VERTEX_MAX];
    int i;
    for(i = 0; i < vs; i++) {
        graph[i].next = &graph[i];
    }
    return graph;
}

void add_list(struct list *head, int dst) {
    struct list *elem = malloc(sizeof(struct list));
    elem->next = head->next;
    elem->dst = dst;
    head->next = elem;
}

struct pair {
    uint64_t whites;
    uint64_t blacks;
};

struct pair add(struct pair p1, struct pair p2) {
    return (struct pair){
        (p1.whites * (p2.whites + p2.blacks))%DIVISOR,
        (p1.blacks * p2.whites)%DIVISOR,
    };
}

struct pair dfs(struct list *graph, int this, int parent) {
    struct list *head = &graph[this];
    struct list *elem;
    struct pair ans = {1, 1};
    for(elem = head->next; elem != head; elem = elem->next) {
        int dst = elem->dst;
        if(dst == parent) continue;
        ans = add(ans, dfs(graph, dst, this));
    }
    return ans;
}

int main(void) {
    int vs = get_int();
    int es = vs - 1;
    int i;
    struct list *graph = create_graph(vs);
    for(i = 0; i < es; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        add_list(&graph[v1], v2);
        add_list(&graph[v2], v1);
    }

    struct pair res = dfs(graph, 0, -1);
    uint64_t ans = (res.whites + res.blacks)%DIVISOR;
    printf("%d\n", (int)ans);
    return 0;
}
