/*
W H N
x1
x2
y1
y2

ex)
10 10 5
1 1 4 9 10
6 10 4 9 10
4 8 1 1 6
4 8 10 5 10
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

struct range {
    int start;
    int end;
};

#define LINE_MAX 500
#define BOUNDARY_MAX (LINE_MAX*3)

void display(int row, int col, struct range *rs, struct range *cs, int size) {
#define SROW_MAX 1000
#define SCOL_MAX 1000
    int i, j, j1, j2;
    static char map[SROW_MAX+1][SCOL_MAX+1];
    memset(map, 0, (SROW_MAX+1)*(SCOL_MAX+1));
    for(i = 0; i < size; i++) {
        struct range r = rs[i];
        struct range c = cs[i];
#ifdef DEBUG
        printf("[%d, %d] -> [%d, %d]\n", r.start, c.start, r.end, c.end);
#endif
        for(j1 = r.start; j1 <= r.end; j1++) {
            for(j2 = c.start; j2 <= c.end; j2++) {
                map[j1][j2] = 1;
            }
        }
    }
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            printf(" %d", map[i][j]);
        }
        putchar('\n');
    }
}

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

#define ROW_MAX 1000000

int compress(struct range *ranges, int size, int limit) {
    int i, j;
    static int map[ROW_MAX+1];
    memset(map, 0, sizeof(int)*(ROW_MAX+1));
    // y
    for(i = 0; i < size; i++) {
        struct range r = ranges[i];
        for(j = -1; j <= 1; j++) {
            map[r.start+j]++;
            map[r.end+j]++;
        }
    }
    map[0] = 0;
    for(i = 1; i <= limit; i++) {
        map[i] = (map[i]>0);
        map[i] += map[i-1];
    }
#ifdef DEBUG
    for(i = 1; i <= limit; i++) {
        printf(" %d", map[i]);
    }
    putchar('\n');
#endif
    for(i = 0; i < size; i++) {
        ranges[i].start = map[ranges[i].start];
        ranges[i].end = map[ranges[i].end];
    }
    return map[limit];
}

struct point2d {
    int row;
    int col;
};

int main(void) {
    int row, col, ls;
    get_int3(&col, &row, &ls);
    struct range rs[LINE_MAX];
    struct range cs[LINE_MAX];

    int i, j;
    for(j = 0; j < ls; j++) {
        scanf("%d", &cs[j].start);
    }
    for(j = 0; j < ls; j++) {
        scanf("%d", &cs[j].end);
    }
    for(j = 0; j < ls; j++) {
        scanf("%d", &rs[j].start);
    }
    for(j = 0; j < ls; j++) {
        scanf("%d", &rs[j].end);
    }

#ifdef DEBUG
    printf("initial state\n");
    display(row, col, rs, cs, ls);
#endif

    int comp_row = compress(rs, ls, row);
    int comp_col = compress(cs, ls, col);
#ifdef DEBUG
    printf("after compression\n");
    display(comp_row, comp_col, rs, cs, ls);
#endif
    return 0;
}
