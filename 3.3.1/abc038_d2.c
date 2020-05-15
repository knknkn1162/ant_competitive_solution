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

struct box {
    int width;
    int height;
};

#define NUM_MAX 100000
#define NUM2_MAX (1<<17)
#define WIDTH_MAX 100000

// already sorted
int asc_by_height(const void *a1, const void *a2) {
    struct box *ba1 = (struct box*)a1;
    struct box *ba2 = (struct box*)a2;
    if(ba1->height == ba2->height) {
        return ba2->width - ba1->width;
    }
    return ba1->height - ba2->height;
}

int lower_bound(int *dp, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(dp[mid] >= key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main(void) {
    int num = get_int();
    int i;
    static struct box boxes[NUM_MAX];

    for(i = 0; i < num; i++) {
        get_int2(&boxes[i].width, &boxes[i].height);
    }

    qsort(boxes, num, sizeof(struct box), asc_by_height);

    // dp[len] = <smallest width>
    static int dp[NUM_MAX+1];
    int idx = 1;
    for(i = 0; i < num; i++) {
        int cur = boxes[i].width;
        if(dp[idx-1] < cur) {
            dp[idx++] = cur;
        } else {
            int nidx = lower_bound(dp, idx, cur);
            dp[nidx] = cur;
        }
    }

    int ans = 1;
    for(i = num; i >= 1; i--) {
        if(!dp[i]) continue;
        ans = i; break;
    }
    printf("%d\n", ans);
    return 0;
}
