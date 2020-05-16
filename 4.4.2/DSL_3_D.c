#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX ((int)(1e+6))

static int deq[NUM_MAX+50];
static int dstart = 0;
static int dend = 0;

void push_back(int val) {
    deq[dend++] = val;
}

int peek_back(void) {
    return deq[dend-1];
}

int pop_front(void) {
    return deq[dstart++];
}

int peek_front(void) {
    return deq[dstart];
}

int lower_bound(int key) {
    int low = dstart-1;
    int high = dend;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(deq[mid] > key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main(void) {
    int num, len;
    static int arr[NUM_MAX];
    static int ans[NUM_MAX];
    int aidx = 0;
    get_int2(&num, &len);
    fget_array(arr, num);
    int i, j;

    for(i = 0; i < num; i++) {
        int cur = arr[i];
        if(peek_back() < cur) {
            push_back(cur);
        } else {
            int nidx = lower_bound(cur);
            dend = nidx;
            push_back(cur);
        }
        if(i >= len) {
            int trash = arr[i-len];
            if(trash == peek_front()) pop_front();
        }
        if(i >= (len-1)) ans[aidx++] = peek_front();
#ifdef DEBUG
        int j;
        for(j = dstart; j < dend; j++) {
            printf(" %d", deq[j]);
        }
        putchar('\n');
#endif
    }

    for(i = 0; i < aidx; i++) {
        printf("%d%c", ans[i], (i == aidx-1) ? '\n' : ' ');
    }

    return 0;
}
