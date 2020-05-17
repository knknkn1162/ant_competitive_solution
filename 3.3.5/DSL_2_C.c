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

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

#define NUM_MAX 500000

struct arrpos {
    int pos;
    int label;
};

int asc_by_pos(const void *a1, const void *a2) {
    struct arrpos *pa1 = (struct arrpos*)a1;
    struct arrpos *pa2 = (struct arrpos*)a2;
    return pa1->pos - pa2->pos;
}

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

struct point2d {
    int x;
    int y;
};

struct range {
    int start;
    int end;
};

int lower_bound(struct arrpos *xs, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(xs[mid].pos >= key) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}


int upper_bound(struct arrpos *xs, int size, int key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(xs[mid].pos <= key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}


int main(void) {
    int num = get_int();
    struct arrpos xs[NUM_MAX]; 
    struct arrpos ys[NUM_MAX];
    int i, j;
    for(i = 0; i < num; i++) {
        int x, y;
        get_int2(&x, &y);
        xs[i] = (struct arrpos){x, i};
        ys[i] = (struct arrpos){y, i};
    }

    qsort(xs, num, sizeof(struct arrpos), asc_by_pos);
    qsort(ys, num, sizeof(struct arrpos), asc_by_pos);
    int queries = get_int();

    for(i = 0; i < queries; i++) {
        static char map[NUM_MAX+1];
        memset(map, 0, NUM_MAX+1);
        static int ans[NUM_MAX];
        int aidx = 0;
        struct point2d start, end;
        get_int4(&start.x, &end.x, &start.y, &end.y);
        struct range rx = {
            lower_bound(xs, num, start.x),
            upper_bound(xs, num, end.x)
        };
        // register
        for(j = rx.start; j <= rx.end; j++) {
            map[xs[j].label]++;
        }

        struct range ry = {
            lower_bound(ys, num, start.y),
            upper_bound(ys, num, end.y)
        };
        for(j = ry.start; j <= ry.end; j++) {
            if(map[ys[j].label]) ans[aidx++] = ys[j].label;
        }
        qsort(ans, aidx, sizeof(int), asc);
        for(j = 0; j < aidx; j++) {
            printf("%d\n", ans[j]);
        }
        putchar('\n');
    }
    return 0;
}

