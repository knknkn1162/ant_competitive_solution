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

struct gas_sta {
    int pos;
    int gas;
};

struct pair {
    int rem;
    int cnt;
    int idx;
};

int asc_by_pos(const void *a1, const void *a2) {
    struct gas_sta *ga1 = (struct gas_sta*)a1;
    struct gas_sta *ga2 = (struct gas_sta*)a2;
    return ga1->pos - ga2->pos;
}

#define NUM_MAX 10000
#define HEAP_MAX 1000000

static struct pair heap[HEAP_MAX];
int hidx = 1;

int cmp(struct pair *this, struct pair *child) {
    return this->cnt < child->cnt;
}

void swap(struct pair *p1, struct pair *p2) {
    struct pair tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void enqueue(struct pair p) {
    heap[hidx++] = p;
    int node = hidx-1;
    int parent;
    while(node>1) {
        parent = node/2;
        if(cmp(&heap[parent], &heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
    return;
}

struct pair pop_min(void) {
    struct pair p = heap[1];
    int node = 1;
    heap[node] = heap[hidx-1];
    hidx--;
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
    return p;
}

int is_empty(void) {
    return hidx==1;
}

int main(void) {
    int num = get_int();
    static struct gas_sta gs[NUM_MAX+2];
    int i;
    gs[0].pos = 0; gs[0].gas = 0;
    for(i = 1; i <= num; i++) {
        get_int2(&gs[i].pos, &gs[i].gas);
    }
    int len, init_gas;
    get_int2(&len, &init_gas);
    gs[num+1].pos = len; gs[num+1].gas = 0;
    qsort(gs, num+2, sizeof(struct gas_sta), asc_by_pos);

    // start
    enqueue((struct pair){init_gas, 0, num+1});

    int ans = -1;
    while(!is_empty()) {
        struct pair p = pop_min();
#ifdef DEBUG
        printf("rem: %d %d %d\n", p.rem, p.cnt, p.idx);
#endif
        int cur = p.idx;
        if(cur == 0) { ans = p.cnt; break; }
        int nrem = p.rem - (gs[cur].pos - gs[cur-1].pos);
        if(nrem < 0) continue;
        enqueue((struct pair){nrem, p.cnt, cur-1});
        enqueue((struct pair){nrem + gs[cur-1].gas, p.cnt+1, cur-1});
    }

    printf("%d\n", ans);
    return 0;
}
