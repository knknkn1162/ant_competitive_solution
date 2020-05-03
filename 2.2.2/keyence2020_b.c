#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

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

struct range {
    int64_t start;
    int64_t end;
};

int asc_by_end(const void *a1, const void *a2) {
    struct range *ra1 = (struct range*)a1;
    struct range *ra2 = (struct range*)a2;
    int64_t ans = ra1->end - ra2->end;
    if(ans<0) return -1;
    if(ans==0) return 0;
    return 1;
}

#define NUM_MAX 100000

int main(void) {
    int num = get_int();
    struct range ranges[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        int center, len;
        get_int2(&center, &len);
        ranges[i] = (struct range){center-len, center+len};
    }

    qsort(ranges, num, sizeof(struct range), asc_by_end);

    int64_t prev = ranges[0].end;
    int cnt = 1;
    for(i = 1; i < num; i++) {
        int64_t cur = ranges[i].end;
        if(prev > ranges[i].start) continue;
        cnt++;
        prev = cur;
    }
    printf("%d\n", cnt);
    return 0;
}
