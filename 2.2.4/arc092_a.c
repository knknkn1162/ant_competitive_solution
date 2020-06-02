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

#define NUM_MAX 100

struct point2d {
    int x;
    int y;
};

struct pair {
    int val;
    int idx;
};

int is_big(struct point2d b, struct point2d s) {
    return b.x > s.x && b.y > s.y;
}

int asc_by_val(const void *a1, const void *a2) {
    struct pair *pa1 = (struct pair*)a1;
    struct pair *pa2 = (struct pair*)a2;
    return pa1->val - pa2->val;
}

struct edge {
    int blue;
    int red;
    int dist2;
};

int asc_by_x(const void *a1, const void *a2) {
    struct point2d *p1 = (struct point2d*)a1;
    struct point2d *p2 = (struct point2d*)a2;
    return p1->x - p2->x;
}

int desc_by_y(const void *a1, const void *a2) {
    struct point2d *p1 = (struct point2d*)a1;
    struct point2d *p2 = (struct point2d*)a2;
    return p2->y - p1->y;
}

int main(void) {
    int num = get_int();
    static struct point2d reds[NUM_MAX];
    static struct point2d blues[NUM_MAX];
    int i, j;

    for(i = 0; i < num; i++) {
        get_int2(&reds[i].x, &reds[i].y);
    }
    for(i = 0; i < num; i++) {
        get_int2(&blues[i].x, &blues[i].y);
    }

    qsort(blues, num, sizeof(struct point2d), asc_by_x);
    qsort(reds, num, sizeof(struct point2d), desc_by_y);

    static int red_map[NUM_MAX+1];
    int ans = 0;
    for(i = 0; i < num; i++) {
        struct point2d bp = blues[i];
        for(j = 0; j < num; j++) {
            struct point2d rp = reds[j];
            if(red_map[j]) continue;
            if(is_big(bp, rp)) {
                ans++;
                red_map[j] = 1;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
