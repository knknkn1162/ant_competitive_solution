#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}


#define VERTEX_MAX 10000
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

void add_list(struct list *head, int v) {
    struct list *elem = &lpool[lidx++];
    elem->dst = v;
    elem->next = head->next;
    head->next = elem;
    return;
}

static int ans[VERTEX_MAX];
static int pos = 0;
static char checked[VERTEX_MAX];
void dfs(struct list *graph, int *outdeg, int node) {
#ifdef DEBUG
    printf("dfs(%d)\n", node);
#endif
    struct list *head = &graph[node];
    struct list *elem;
    ans[pos++] = node;
    checked[node] = 1;
    for(elem = head->next; elem != head; elem = elem->next) {
        int dst = elem->dst;
        outdeg[dst]--;
        if(outdeg[dst]) continue;
        dfs(graph, outdeg, dst);
    }
}

int main(void) {
    int vs, es;
    get_int2(&vs, &es);
    struct list *graph = create_graph(vs);
    static int outdeg[VERTEX_MAX];

    int i;
    for(i = 0; i < es; i++) {
        int src, dst;
        get_int2(&src, &dst);
        add_list(&graph[src], dst);
        outdeg[dst]++;
    }

    for(i = 0; i < vs; i++) {
        if(!outdeg[i] && !checked[i]) dfs(graph, outdeg, i);
#ifdef DEBUG
        int j;
        printf("%d: ", i);
        for(j = 0; j < vs; j++) {
            printf("%d ", outdeg[j]);
        }
        putchar('\n');
#endif
    }

    // presentation
    for(i = 0; i < vs; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
