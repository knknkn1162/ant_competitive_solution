#define HEAP_MAX 100000
static int heap[HEAP_MAX];
#define ROOT_NODE 1
static int hidx = ROOT_NODE;

// smaller
int cmp(int a1, int a2) {
    return a1 < a2;
}

void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

int is_empty(void) {
    return hidx == ROOT_NODE;
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

int dequeue_min(void) {
    int ans = heap[ROOT_NODE];
    int node = ROOT_NODE;
    heap[ROOT_NODE] = heap[--hidx];
    while(1) {
        int this = node;
        int left = node * 2;
        int right = node * 2 + 1;
        if(left < hidx && !cmp(heap[this], heap[left])) {
            this = left;
        }
        if(right < hidx && !cmp(heap[this], heap[right])) {
            this = right;
        }
        if(this == node) break;
        swap(&heap[this], &heap[node]);
        node = this;
    }
    return ans;
}

