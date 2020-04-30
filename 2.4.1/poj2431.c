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

int asc_by_pos(const void *a1, const void *a2) {
    struct gas_sta *ga1 = (struct gas_sta*)a1;
    struct gas_sta *ga2 = (struct gas_sta*)a2;
    return ga1->pos - ga2->pos;
}

#define NUM_MAX 10000
#define HEAP_MAX NUM_MAX+50

static int heap[HEAP_MAX];
int hidx = 1;

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int cmp(int *this, int *child) {
    return *this > *child;
}

void enqueue(int p) {
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

int pop_max(void) {
    int p = heap[1];
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
    static struct gas_sta gs[NUM_MAX+1];
    int i;
    for(i = 0; i < num; i++) {
        get_int2(&gs[i].pos, &gs[i].gas);
    }
    int len, init_gas;
    get_int2(&len, &init_gas);
    // gs[i].pos: the dist from the starting point
    for(i = 0; i < num; i++) {
        gs[i].pos = len-gs[i].pos;
    }
    gs[num].pos = len; gs[num].gas = 0;
    qsort(gs, num, sizeof(struct gas_sta), asc_by_pos);
    int idx = 0;
    int dist = 0;
    int cnt = 0;
    enqueue(init_gas);
    // start
    int ans = -1;
    while(!is_empty()) {
#ifdef DEBUG
        printf("%d: cnt: %d\n", idx, cnt);
#endif
        if(dist >= len) { ans = cnt-1; break; }
        int fuel = pop_max();
        dist += fuel;
        cnt++;
        while(idx < num) {
            if(gs[idx].pos > dist) break;
            enqueue(gs[idx].gas);
            idx++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
