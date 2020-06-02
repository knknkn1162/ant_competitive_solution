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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
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

#define ROW_MAX 300
#define COL_MAX 300

struct point2d {
    int x;
    int y;
};

int dist(struct point2d p1, struct point2d p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
#define QUERY_MAX 100000

int main(void) {
    int row, col, d;
    get_int3(&row, &col, &d);
    static struct point2d map[ROW_MAX*COL_MAX];
    int i, j;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            int label = get_int();
            map[label] = (struct point2d){i, j};
        }
    }

    int rem;
    static int64_t cum[ROW_MAX*COL_MAX+1];
    for(rem = 0; rem < d; rem++) {
        int ulimit = ((row*col)-rem)/d;
        int prev = rem;
        for(i = 1; i <= ulimit; i++) {
            int cur = i*d+rem;
            cum[cur] = cum[prev] + dist(map[prev], map[cur]);
            prev = cur;
        }
    }

    int queries = get_int();
    static int64_t ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < queries; i++) {
        int start, goal;
        get_int2(&start, &goal);
        ans[aidx++] = cum[goal] - cum[start];
    }
    
    for(i = 0; i < aidx; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
