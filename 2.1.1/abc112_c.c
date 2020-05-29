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

struct cond {
    int x;
    int y;
    int height;
};
#define NUM_MAX 100
#define POS_MAX 100

int func(int x, int y, int top, int cx, int cy) {
    int dist1 = abs(cx-x)+abs(cy-y);
    return max(0, top-dist1);
}

int main(void) {
    int num = get_int();
    struct cond conds[NUM_MAX];

    int i;
    int pivot = 0;
    for(i = 0; i < num; i++) {
        get_int3(&conds[i].x, &conds[i].y, &conds[i].height);
        if(conds[i].height) pivot = i;
    }

    int cx, cy;
    int top = 0;
    for(cx = 0; cx <= POS_MAX; cx++) {
        for(cy = 0; cy <= POS_MAX; cy++) {
            int flag = 1;
            // calc height for pivot
            top = conds[pivot].height + abs(conds[pivot].x-cx) + abs(conds[pivot].y-cy);
            for(i = 0; i < num; i++) {
                if(func(conds[i].x, conds[i].y, top, cx, cy) != conds[i].height) {
                    flag = 0; break;
                }
            }
            if(flag) {
                goto finish;
            }
        }
    }
finish:
    printf("%d %d %d\n", cx, cy, top);
    return 0;
}
