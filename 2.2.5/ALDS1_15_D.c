#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define STR_MAX 100000
#define BUF_SIZE (STR_MAX+50)

struct pair {
    int cnt;
    char idx;
    struct pair *left;
    struct pair *right;
};

#define ROOT_NODE 1
#define HEAP_MAX 50
static struct pair *heap[HEAP_MAX];
static int hidx = ROOT_NODE;

// min-heap
int cmp(struct pair *a, struct pair *b) {
    return a->cnt < b->cnt;
}

void swap(struct pair **a, struct pair **b) {
    struct pair *tmp = *a;
    *a = *b;
    *b = tmp;
}

void enqueue(struct pair *val) {
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

struct pair *get_min(void) {
    struct pair* ans = heap[ROOT_NODE];
    heap[ROOT_NODE] = heap[--hidx];
    int node = ROOT_NODE;
    while(1) {
        int cur = node;
        int left = node*2;
        int right = node*2+1;
        if(left < hidx && !cmp(heap[cur], heap[left])) cur = left;
        if(right < hidx && !cmp(heap[cur], heap[right])) cur = right;
        if(cur == node) break;
        swap(&heap[node], &heap[cur]);
        node = cur;
    }
    return ans;
}

int get_count(void) {
    return hidx-1;
}

void get_depth(struct pair *node, int val, int *out) {
    if(node->idx != -1) out[node->idx] = val;
    if(node->left) get_depth(node->left, val+1, out);
    if(node->right) get_depth(node->right, val+1, out);
    return;
}

struct pair *create_pair(int cnt) {
    static struct pair pool[100];
    static int pidx = 0;
    struct pair *p = &pool[pidx++];
    p->cnt = cnt; p->idx = -1;
    return p;
}

int main(void) {
    char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int len = strlen(str);

    int map[26] = {0};
    int i;
    int kinds = 0;
    for(i = 0; i < len; i++) {
        map[str[i] - 'a']++;
    }

    struct pair ps[26];
    for(i = 0; i < 26; i++) {
        if(!map[i]) continue;
        kinds++;
        ps[i] = (struct pair){map[i], i, NULL, NULL};
        enqueue(&ps[i]);
    }
    int ans = 0;
    if(kinds==1) {
        ans = len;
        goto finish;
    }

    while(get_count() > 1) {
        struct pair *p1 = get_min();
        struct pair *p2 = get_min();
        struct pair *np = create_pair(p1->cnt + p2->cnt);
#ifdef DEBUG
        printf("%d %d\n", p1->cnt, p2->cnt);
#endif
        np->left = p1; np->right = p2;
        enqueue(np);
    }
    int codes[26] = {0};
    struct pair *root = heap[ROOT_NODE];
    get_depth(root, 0, codes);

    for(i = 0; i < 26; i++) {
        ans += codes[i]*map[i];
    }
finish:
    printf("%d\n", ans);

    return 0;
}
