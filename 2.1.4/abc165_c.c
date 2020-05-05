#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
 
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30
#define DIVISOR 1000000007

int get_int3(int *a1, int *a2, int *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d", a1, a2, a3);
#else
#error
#endif
  return 0;
}
 
int get_int4(int *a1, int *a2, int *a3, int *a4) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d %d", a1, a2, a3, a4);
#else
#error
#endif
  return 0;
}
 
struct query {
    int v1;
    int v2;
    int dist;
    int point;
};
 
#define QUERY_MAX 50
#define NUM_MAX 10
 
int desc_by_point(const void *a1, const void *a2) {
    struct query *qa1 = (struct query*)a1;
    struct query *qa2 = (struct query*)a2;
    return qa2->point - qa1->dist;
}
 

int main(void) {
    int num, limit, qs;
    struct query queries[QUERY_MAX];
    get_int3(&num, &limit, &qs);
 
    int i;
    for(i = 0; i < qs; i++) {
        int v1, v2, dist, point;
        get_int4(&v1, &v2, &dist, &point);
        v1--; v2--;
        queries[i] = (struct query){v1, v2, dist, point};
    }
    qsort(queries, qs, sizeof(struct query), desc_by_point);

    int sum = num + limit - 1;
    int pat;
    int ans = 0;
    for(pat = 1; pat < (1<<sum); pat++) {
        int cnt = __builtin_popcount(pat);
        if(cnt != num) continue;
        int as[NUM_MAX] = {0};
        int aidx = 0; int bidx = 0;
        for(i = 0; i < sum; i++) {
            int flag = (pat & (1<<i));
            if(flag) {
                as[aidx++] = bidx;
            } else {
                bidx++;
            }
        }
        int res = 0;
        for(i = 0; i < qs; i++) {
            struct query q = queries[i];
            if(q.dist == as[q.v2] - as[q.v1]) res += q.point;
        }
        ans = max(res, ans);
    }
    printf("%d\n", ans);
 
    return 0;
}
