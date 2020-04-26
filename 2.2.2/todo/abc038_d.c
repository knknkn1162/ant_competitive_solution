#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 0

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

#define NUM_MAX 100000

struct point2d {
    int x;
    int y;
};

int asc_x(const void *a1, const void *a2) {
    struct point2d *pa1 = (struct point2d*)a1;
    struct point2d *pa2 = (struct point2d*)a2;
    int ma1 = min(pa1->x, pa1->y);
    int ma2 = min(pa2->x, pa2->y);

    int diff = ma1 - ma2;
    if(!diff) return pa1->y - pa2->y;
    return pa1->x - pa2->x;
}

int main(void) {
    int num = get_int();
    struct point2d ps[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        get_int2(&ps[i].x, &ps[i].y);
    }
    qsort(ps, num, sizeof(struct point2d), asc_x);

    struct point2d prev = ps[0];
    int cnt = 1;
    for(i = 1; i < num; i++) {
    }
    return 0;
}
