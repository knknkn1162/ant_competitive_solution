#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

int get_int5(int *a1, int *a2, int *a3, int *a4, int *a5) {
  scanf("%d %d %d %d %d", a1, a2, a3, a4, a5);
  return 0;
}

struct edge{
    int girl;
    int boy;
    int point;
};

#define NUM_MAX 18
#define EDGE_MAX 10000

int desc(const void *a1, const void *a2) {
    return *(int*)a2 - *(int*)a1;
}

int main(void) {
    int boys, girls;
    int group_boys, group_girls;
    int es;
    struct edge edges[EDGE_MAX];
    get_int5(&girls, &boys, &group_girls, &group_boys, &es);
    int i;
    for(i = 0; i < es; i++) {
        int src, dst, point;
        get_int3(&src, &dst, &point);
        // 1-indexed -> 0-indexed
        src--; dst--;
        edges[i] = (struct edge){src, dst, point};
    }

    int pat;
    int ans = 0;
    for(pat = 1; pat < (1<<girls); pat++) {
        if(__builtin_popcount(pat) != group_girls) continue;
        int points[NUM_MAX] = {0};
        for(i = 0; i < es; i++) {
            struct edge e = edges[i];
            if(!(pat & (1<<e.girl))) continue;
            points[e.boy] += e.point;
        }
        qsort(points, boys, sizeof(int), desc);
        int sum = 0;
        for(i = 0; i < group_boys; i++) {
            sum += points[i];
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}
