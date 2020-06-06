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


#define VERTEX_MAX 100000
// undirected
#define EDGE_MAX (100000*2)
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
}

void get_dist(struct list *graph, int node, int parent, int *out) {
    if(parent == -1) {
        out[node] = 0;
    } else {
        out[node] = out[parent]+1;
    }
    struct list *elem;
    struct list *head = &graph[node];
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->dst == parent) continue;
        get_dist(graph, elem->dst, node, out);
    }
    return;
}


int main(void) {
    int num = get_int();
    struct list *graph = create_graph(num);
    int i;
    for(i = 0; i < num-1; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        v1--; v2--;
        add_list(&graph[v1], v2);
        add_list(&graph[v2], v1);
    }

    static int aout[VERTEX_MAX];
    static int bout[VERTEX_MAX];
    get_dist(graph, 0, -1, aout);
    get_dist(graph, num-1, -1, bout);

    int blacks = 0;
    int whites = 0;
    for(i = 0; i < num; i++) {
        if(aout[i] <= bout[i]) {
            blacks++;
        } else {
            whites++;
        }
    }
#ifdef DEBUG
    printf("%d vs %d\n", blacks, whites);
#endif
    printf("%s\n", blacks > whites ? "Fennec" : "Snuke");
    return 0;
}
