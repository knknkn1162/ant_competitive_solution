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

#define NUM2_MAX (1<<18)
#define NUM_MAX 200000
#define QUERY_MAX 200000

enum type {
    COMMAND_ADD = 1,
    COMMAND_REQUEST = 2,
};

void update(int *seg, int val, int idx) {
    int node = NUM2_MAX+idx;
    seg[node] = val;
    while((node = (node/2))) {
        seg[node] = seg[node*2] + seg[node*2+1];
    }
    return;
}
#define ROOT_NODE 1
struct range {
    int start;
    int end;
};

int is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

int is_contain(struct range elem, struct range box) {
    return box.start <= elem.start && elem.end <= box.end;
}

int get_sum(int *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) {
        return seg[node];
    }
    struct range left = { nr.start, (nr.start + nr.end)/2 };
    struct range right = { (nr.start+nr.end)/2, nr.end };
    return get_sum(seg, r, node*2, left) + get_sum(seg, r, node*2+1, right);
}

int find(int *seg, int order) {
    int low = 0;
    int high = NUM_MAX+1;
    struct range whole = {0, NUM2_MAX+1};
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        struct range r = {0, mid+1};
        int sum = get_sum(seg, r, ROOT_NODE, whole);
#ifdef DEBUG
        printf("mid: %d: %d\n", mid, sum);
#endif
        if(sum < order) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(void) {
    int queries = get_int();
    int i;

    // int
    static int seg[NUM2_MAX*2];
    static int ans[QUERY_MAX];
    int aidx = 0;

    for(i = 0; i < queries; i++) {
        int type, idx;
        get_int2(&type, &idx);
        switch(type) {
            case COMMAND_ADD:
                update(seg, 1, idx);
                break;
            case COMMAND_REQUEST:
                {
                    int num = find(seg, idx) + 1;
                    update(seg, 0, num);
                    ans[aidx++] = num;
                }
                break;
            default:
                break;
        }
    }
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
