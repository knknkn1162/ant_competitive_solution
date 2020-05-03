#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define TOWNS_MAX 100000
#define ROADS_MAX 100000
#define BUF_SIZE (TOWNS_MAX*7+50)

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



// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

struct list {
    struct list *next;
    int dst;
    int time;
};

struct list *create_graph(int vs) {
    struct list *graph = malloc(vs*sizeof(struct list));
    int i;
    for(i = 0; i < vs; i++) {
        graph[i].next = &graph[i];
    }
    return graph;
}

#define LPOOL_MAX (ROADS_MAX*2+50)
static struct list lpool[LPOOL_MAX];
static int lidx;
#define INF 0x3f3f3f3f

void add_list(struct list *head, int dst, int time) {
    struct list *elem = &lpool[lidx++];
    elem->next = head->next;
    elem->dst = dst;
    elem->time = time;
    head->next = elem;
}


struct pair {
    int town;
    int time;
};

// max heap
#define HEAP_MAX 1000000
static struct pair heap[HEAP_MAX];
static int hidx = 1;

void reset_heap(void) {
    hidx = 1;
}

int cmp(struct pair *this, struct pair *child) {
    return this->time < child->time;
}

void swap(struct pair *p1, struct pair *p2) {
    struct pair tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void enqueue(struct pair p) {
    int node = hidx;
    heap[hidx++] = p;
    int parent;
    while((parent = node/2)) {
        if(cmp(&heap[parent], &heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
    return;
}

struct pair pop_min(void) {
    struct pair ans = heap[1];
    heap[1] = heap[--hidx];
    int node = 1;
    while(1) {
        int smallest = node;
        int left = node*2;
        int right = node*2+1;
        if(left < hidx && !cmp(&heap[smallest], &heap[left])) {
            smallest = left;
        }
        if(right < hidx && !cmp(&heap[smallest], &heap[right])) {
            smallest = right;
        }
        if(smallest == node) break;
        swap(&heap[smallest], &heap[node]);
        node = smallest;
    }
    return ans;
}

int is_empty(void) {
    return hidx == 1;
}

void dijkstra(struct list *graph, int *costs, int size, int tlimit) {
    reset_heap();
    struct list *elem;
    enqueue((struct pair){0, 0});
    while(!is_empty()) {
        struct pair p = pop_min();
#ifdef DEBUG
        printf("dijk: %d %d\n", p.town, p.time);
#endif
        struct list *head = &graph[p.town];
        for(elem = head->next; elem != head; elem = elem->next) {
            int dst = elem->dst;
            int new = costs[p.town] + elem->time;
            if(costs[dst] > new) {
                if(new >= tlimit) continue;
                costs[dst] = new;
                enqueue((struct pair){dst, new});
            }
        }
    }
}

int main(void) {
    int vs, es, tlimit;
    static int bonus[TOWNS_MAX];
    get_int3(&vs, &es, &tlimit);
    fget_array(bonus, vs);

    int i;
    struct list *graph1 = create_graph(vs);
    struct list *graph2 = create_graph(vs);

    for(i = 0; i < es; i++) {
        int src, dst, time;
        get_int3(&src, &dst, &time);
        // 1-indexed -> 0-indexed
        src--; dst--;
        add_list(&graph1[src], dst, time);
        add_list(&graph2[dst], src, time);
    }

    // Dijkstra algorithm
    // 0: outward 1: return
    static int costs[2][TOWNS_MAX];
    memset(costs, 0x3f, sizeof(int)*(TOWNS_MAX*2));
    costs[0][0] = costs[1][0] = 0;
    dijkstra(graph1, costs[0], vs, tlimit);
    dijkstra(graph2, costs[1], vs, tlimit);

    uint64_t ans = 0;
    for(i = 0; i < vs; i++) {
        // cannot reach i
        if(costs[0][i] == INF) continue;
        if(costs[1][i] == INF) continue;
        int64_t rem = tlimit-costs[0][i]- costs[1][i];
        if(rem<=0) continue;
        ans = max(ans, rem*(uint64_t)bonus[i]);
    }
    printf("%llu\n", ans);

    return 0;
}
