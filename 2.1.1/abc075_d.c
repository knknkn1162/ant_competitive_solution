#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

#define NUM_MAX 50

struct point2d {
    int x;
    int y;
};

struct rect {
    struct point2d bottom;
    struct point2d top;
};

int64_t get_area(struct rect r) {
#ifdef DEBUG
    printf("(%d, %d) (%d, %d)\n", r.bottom.x, r.bottom.y, r.top.x, r.top.y);
#endif
    return (int64_t)(r.top.x-r.bottom.x)*(int64_t)(r.top.y-r.bottom.y);
}

int count_points(struct rect r, struct point2d* ps, int size) {
    int i;
    int count = 0;
    for(i = 0; i < size; i++) {
        struct point2d p = ps[i];
        count += (r.bottom.x <= p.x && p.x <= r.top.x) && (r.bottom.y <= p.y && p.y <= r.top.y);
    }
    return count;
}

struct range {
    int start;
    int end;
};

#define LEN_MAX ((2e+9)+1)
#define AREA_MAX (4e+18)

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int num, llimit;
    get_int2(&num, &llimit);
    struct point2d ps[NUM_MAX];

    int i, j;
    for(i = 0; i < num; i++) {
        get_int2(&ps[i].x, &ps[i].y);
    }

    int64_t min_area = AREA_MAX;
    int pos[NUM_MAX];
    int k;
    for(i = 0; i < num; i++) {
        struct point2d p1 = ps[i];
        for(j = i+1; j < num; j++) {
            int64_t res1 = LEN_MAX;
            int64_t res2 = LEN_MAX;
            int pidx = 0;
            struct point2d p2 = ps[j];
            struct range rx = (struct range){
                min(p1.x, p2.x),
                max(p1.x, p2.x),
            };
            for(k = 0; k < num; k++) {
                if(rx.start <= ps[k].x && ps[k].x <= rx.end) pos[pidx++] = ps[k].y;
            }
            qsort(pos, pidx, sizeof(int), asc);
            for(k = llimit-1; k < pidx; k++) {
                res1 = min(res1, pos[k]-pos[k-(llimit-1)]);
            }
            if(res1 != LEN_MAX) min_area = min(min_area, res1*(rx.end-rx.start));

            pidx = 0;
            struct range ry = (struct range){
                min(p1.y, p2.y),
                max(p1.y, p2.y),
            };
            for(k = 0; k < num; k++) {
                if(ry.start <= ps[k].y && ps[k].y <= ry.end) pos[pidx++] = ps[k].x;
            }
            qsort(pos, pidx, sizeof(int), asc);
            for(k = llimit-1; k < pidx; k++) {
                res2 = min(res2, pos[k]-pos[k-(llimit-1)]);
            }
            if(res2 != LEN_MAX) min_area = min(min_area, res2*(ry.end-ry.start));
        }
    }
    printf("%lld\n", min_area);
    return 0;
}
