#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

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

#define NUM_MAX 200000

struct range {
    int start;
    int end;
};

int asc_by_end(const void *a1, const void *a2) {
    struct range *va1 = (struct range*)a1;
    struct range *va2 = (struct range*)a2;
    return va1->end - va2->end;
}

int main(void) {
    int num = get_int();
    struct range ranges[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        int pos, weight;
        get_int2(&pos, &weight);
        ranges[i] = (struct range){pos-weight, pos+weight};
    }
    qsort(ranges, num, sizeof(struct range), asc_by_end);

    int cnt = 1;
    struct range prev = ranges[0];
    for(i = 1; i < num; i++) {
        struct range cur = ranges[i];
        if(prev.end > cur.start) continue;
        cnt++;
        prev = cur;
    }
    printf("%d\n", cnt);
    return 0;
}
