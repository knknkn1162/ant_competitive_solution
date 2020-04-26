#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define VERTEX_MAX 100000
#define BUF_SIZE 20

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

struct range {
    int start;
    int end;
};

int asc_by_start(const void *a1, const void *a2) {
    struct range *ra1 = (struct range*)a1;
    struct range *ra2 = (struct range*)a2;
    return ra1->start - ra2->start;
}

int main(void) {
    int vs, queries;
    get_int2(&vs, &queries);
    struct range ranges[VERTEX_MAX+1];
    int i;
    for(i = 0; i < queries; i++) {
        int s, e;
        get_int2(&s, &e);
        // 1-indexed -> 0-indexed
        s--; e--;
        ranges[i] = (struct range){s, e};
    }
    ranges[queries] = (struct range){VERTEX_MAX+1, VERTEX_MAX+2};
    qsort(ranges, queries, sizeof(struct range), asc_by_start);
    int cnt = 0;
    struct range prev = ranges[0];
    for(i = 1; i < queries+1; i++) {
        struct range cur = ranges[i];
        if(prev.end - 1 >= cur.start) {
            prev.end = min(prev.end, cur.end);
            continue;
        }
#ifdef DEBUG
        printf("cur: [%d, %d], prev: [%d %d]\n",
            cur.start, cur.end,
            prev.start, prev.end
        );
#endif
        cnt++;
        prev = cur;
    }
    printf("%d\n", cnt);
    return 0;
}
