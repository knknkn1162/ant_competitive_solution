/*
4
3 1 4 2
 */
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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)
#define ROOT_NODE 1

struct range {
    int start;
    int end;
};

int get_val(int *seg, int num, int idx) {
    int node = num + idx;
    int ans = 0;
    while(node) {
        ans += seg[node];
        node /= 2;
    }
    return ans;
}

int is_contain(struct range elem, struct range box) {
    return box.start <= elem.start && elem.end <= box.end;
}

int is_overlap(struct range r1, struct range r2) {
    return r1.start <= r2.end && r2.start <= r1.end;
}

void add_range(int *seg, int val, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return;
    if(is_contain(nr, r)) {
        seg[node] += val;
    } else {
        struct range left = { nr.start, (nr.start+nr.end)/2 };
        struct range right = { left.end+1, nr.end };
        add_range(seg, val, r, node*2, left);
        add_range(seg, val, r, node*2+1, right);
    }
}

int main(void) {
    int num = get_int();
    int num2 = 1;
    while(num >= num2) num2 *= 2;
    static int seg[NUM2_MAX];

    static int arr[NUM_MAX];
    fget_array(arr, num);
    static int pos[NUM_MAX+1];
    int i;
    for(i = 0; i < num; i++) {
        pos[arr[i]] = (i+1); // 0-indexed
    }
    for(i = 0; i < num; i++) {
        // diff
        seg[num2+i] = arr[i] - (i+1);
    }

    int64_t cnt = 0;
    struct range whole = {0, num2-1};
    for(i = 1; i < num; i++) {
        int p = pos[i];
        int diff = get_val(seg, num, p);
#ifdef DEBUG
        printf("pos: %d, diff: %d\n", p, diff);
#endif
        if(diff == 0) continue;
        cnt += abs(diff);
        int sign = (diff > 0) ? 1 : -1;
        struct range r = {0, p-1};
        if(p==0) continue;
        add_range(seg, -sign, r, ROOT_NODE, whole);
    }
    printf("%lld\n", cnt);
    return 0;
}
