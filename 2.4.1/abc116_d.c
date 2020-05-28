#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

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

struct sushi {
    int neta;
    int point;
};

#define NUM_MAX 100000
#define TYPES_MAX (NUM_MAX)

int desc_by_point(const void *a1, const void *a2) {
    struct sushi *s1 = (struct sushi*)a1;
    struct sushi *s2 = (struct sushi*)a2;
    return s2->point - s1->point;
}
#define HEAP_MAX (NUM_MAX+100)
#define ROOT_NODE 1
static struct sushi* heap[HEAP_MAX];
static int hidx = ROOT_NODE;
int is_prio_empty(void) { return hidx == ROOT_NODE; }

int comp(struct sushi *a1, struct sushi *a2) {
    return a1->point > a2->point;
}

void swap(struct sushi **a1, struct sushi **a2) {
    struct sushi *tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

// max heap
void enqueue(struct sushi *s) {
    int node = hidx;
    heap[hidx++] = s;
    int parent;
    while((parent = node/2)) {
        if(comp(heap[parent], heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
    return;
}

struct sushi *delete_max(void) {
    struct sushi *ans = heap[ROOT_NODE];
    heap[ROOT_NODE] = heap[--hidx];
    int node = ROOT_NODE;
    while(1) {
        int largest = node;
        int left = node * 2;
        int right = node * 2 + 1;
        if(left < hidx && !comp(heap[largest], heap[left])) {
            largest = left;
        }
        if(right < hidx && !comp(heap[largest], heap[right])) {
            largest = right;
        }
        if(node == largest) break;
        swap(&heap[node], &heap[largest]);
        node = largest;
    }
    return ans;
}


static struct sushi* stack[NUM_MAX+50];
static int sidx = 0;

int is_stack_empty(void) { return !sidx; }
void push(struct sushi *s) { stack[sidx++] = s; }
struct sushi *pop(void) { return stack[--sidx]; }


int main(void) {
    int num, k;
    get_int2(&num, &k);

    int i;
    static struct sushi sushis[NUM_MAX];
    for(i = 0; i < num; i++) {
        get_int2(&sushis[i].neta, &sushis[i].point);
    }
    qsort(sushis, num, sizeof(struct sushi), desc_by_point);

    static char checked[TYPES_MAX+1];
    int64_t base = 0;
    for(i = 0; i < num; i++) {
        struct sushi s = sushis[i];
        if(sidx >= k || checked[s.neta]) {
            enqueue(&sushis[i]);
            continue;
        }
        checked[s.neta]++;
        base += s.point;
        push(&sushis[i]);
    }
    // if (# of types) < K
    for(i = sidx; i < k; i++) {
        struct sushi *s = delete_max();
        base += s->point;
    }

#ifdef DEBUG
        printf("[stack: %d heap: %d] %lld\n", sidx, hidx, base);
#endif
    int64_t ans = base + (int64_t)sidx*sidx; // when x=max

    while(!is_stack_empty() && !is_prio_empty()) {
        struct sushi *trash = pop();
        struct sushi *s = delete_max();
        base = base - trash->point + s->point;
#ifdef DEBUG
        printf("[stack: %d heap: %d] %lld\n", sidx, hidx, base);
#endif
        ans = max(ans, base + (int64_t)sidx*sidx);
    }

    printf("%lld\n", ans);
    return 0;
}
