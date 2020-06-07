#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

struct point2d {
    int x;
    int y;
};

enum direction {
    ENUM_RIGHT = 'R',
    ENUM_LEFT = 'L',
    ENUM_UP = 'U',
    ENUM_DOWN = 'D'
};

#define NUM_MAX 20000
static char buffer[NUM_MAX];
int bidx = 0;
void ccw(struct point2d start, struct point2d end) {
    int i;
    if(start.x < end.x && start.y < end.y) {
        for(i = start.x; i < end.x; i++) {
            buffer[bidx++] = ENUM_RIGHT;
        }
        for(i = start.y; i < end.y; i++) {
            buffer[bidx++] = ENUM_UP;
        }
    } else {
        for(i = start.x; i > end.x; i--) {
            buffer[bidx++] = ENUM_LEFT;
        }
        for(i = start.y; i > end.y; i--) {
            buffer[bidx++] = ENUM_DOWN;
        }
    }
}

int main(void) {
    struct point2d start;
    struct point2d end;
    get_int4(&start.x, &start.y, &end.x, &end.y);

    ccw(start, end);
    ccw(end, start);

    // round2
    // forth
    struct point2d start2 = {start.x, start.y-1};
    struct point2d end2 = {end.x+1, end.y};
    buffer[bidx++] = ENUM_DOWN;
    ccw(start2, end2);
    buffer[bidx++] = ENUM_LEFT;
    // back
    end2 = (struct point2d){end.x, end.y+1};
    start2 = (struct point2d){start.x-1, start.y};
    buffer[bidx++] = ENUM_UP;
    ccw(end2, start2);
    buffer[bidx++] = ENUM_RIGHT;

#ifdef DEBUG
    printf("length: %d\n", bidx);
#endif
    printf("%s\n", buffer);
    return 0;
}
