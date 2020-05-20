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

#define QUERY_MAX 2000000

enum type {
    COMMAND_EXTRACT = 'e',
    COMMAND_INSERT = 'i',
};

#define ROOT_NODE 1
static int heap[QUERY_MAX+50];
int hidx = ROOT_NODE;

// max-heap
int cmp(int a, int b) {
    return a > b;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void enqueue(int val) {
    int node = hidx;
    heap[hidx++] = val;
    int parent;
    while((parent = node/2)) {
        if(cmp(heap[parent], heap[node])) break;
        swap(&heap[parent], &heap[node]);
        node = parent;
    }
    return;
}

int get_min(void) {
    int ans = heap[ROOT_NODE];
    heap[ROOT_NODE] = heap[--hidx];
    int node = ROOT_NODE;
    while(1) {
        int cur = node;
        int left = node*2;
        int right = node*2+1;
        if(left < hidx && !cmp(heap[cur], heap[left])) cur = left;
        if(right < hidx && !cmp(heap[cur], heap[right])) cur = right;
        if(cur == node) break;
        swap(&heap[cur], &heap[node]);
        node = cur;
    }
    return ans;
}

int main(void) {
    static int ans[QUERY_MAX];
    int aidx = 0;
    while(1) {
        char command[12] = {0};
        int val;
        scanf("%s", command);
        if(command[0] == 'e' && command[1] == 'n') break;
        switch(command[0]) {
            case COMMAND_EXTRACT:
                ans[aidx++] = get_min();
                break;
            case COMMAND_INSERT:
                scanf("%d", &val);
                enqueue(val);
                break;
            default:
                break;
        }
    }

    int i;
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
