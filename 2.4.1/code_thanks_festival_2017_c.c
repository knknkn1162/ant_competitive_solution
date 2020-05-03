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

struct pair {
    uint64_t time;
    int next;
};

#define NUM_MAX 100000
#define HEAP_MAX (NUM_MAX+50)

static struct pair heap[HEAP_MAX];
static int hidx = 1;

int asc_by_time(const void *a1, const void *a2) {
    struct pair *pa1 = (struct pair*)a1;
    struct pair *pa2 = (struct pair*)a2;
    return pa1->time - pa2->time;
}

int cmp(struct pair *a1, struct pair *a2) {
    return asc_by_time(a1, a2) < 0;
}

void swap(struct pair *p1, struct pair *p2) {
    struct pair tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void enqueue(struct pair p) {
    int node = hidx;
    heap[hidx++] = p;
    while(node>1) {
        int parent = node/2;
        if(cmp(&heap[parent], &heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
}

struct pair pop_min(void) {
    struct pair p = heap[1];
    heap[1] = heap[--hidx];
    int node = 1;
    while(1) {
        int smallest = node;
        int left = node * 2;
        int right = node * 2 + 1;
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
    return p;
}

int main(void) {
    int num, k;
    get_int2(&num, &k);
    int i;
    for(i = 0; i < num; i++) {
        int init, next;
        get_int2(&init, &next);
        heap[hidx++] = (struct pair){init, next};
    }
    qsort(heap, hidx, sizeof(struct pair), asc_by_time);

    uint64_t ans = 0;
    for(i = 0; i < k; i++) {
        struct pair p = pop_min();
#ifdef DEBUG
        printf("%d: %llu\n", i, p.time);
#endif
        ans += p.time;
        struct pair np = {p.time+(uint64_t)p.next, p.next};
        enqueue(np);
    }
    printf("%lld\n", ans);
    return 0;
}
