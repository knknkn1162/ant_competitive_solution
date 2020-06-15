
#define VERTEX_MAX 100000
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
