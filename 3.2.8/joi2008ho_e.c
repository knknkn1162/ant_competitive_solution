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

#define COL_MAX 1000001
#define ROW_MAX COL_MAX
#define NUM_MAX 1000
// start, end
#define COMP_COL_MAX (NUM_MAX*6)
#define COMP_ROW_MAX (NUM_MAX*6)
struct range {
    int start;
    int end;
};

struct point2d {
    int row;
    int col;
};

int compress(struct range *rs, int num, int size) {
    static int map[ROW_MAX+2];
    memset(map, 0, sizeof(int)*(ROW_MAX+2));

    int i, j;
    for(i = 0; i < num; i++) {
        struct range r = rs[i];
        for(j = -1; j <= 1; j++) {
            map[r.start+j]++;
            map[r.end+j]++;
        }
    }

    // bin sort
    map[0] = 0;
    for(i = 1; i <= size; i++) {
        map[i] = (map[i]>0);
        map[i] += map[i-1];
    }
#ifdef DEBUG
    for(i = 1; i <= size; i++) {
        printf(" %d", map[i]);
    }
    putchar('\n');
#endif

    for(i = 0; i < num; i++) {
        struct range r = rs[i];
        rs[i].start = map[r.start];
        rs[i].end = map[r.end];
    }
    return map[size];
}

enum type {
    ENUM_PATH,
    ENUM_WALL,
};

void create_map(char map[][COMP_COL_MAX+2], struct range *rs, struct range *cs, int num, struct point2d size) {
    int i, k1, k2;
    for(i = 0; i <= size.row+1; i++) {
        map[i][0] = map[i][size.col+1] = ENUM_WALL;
    }

    for(i = 0; i <= size.col+1; i++) {
        map[0][i] = map[size.row+1][i] = ENUM_WALL;
    }

    for(i = 0; i < num; i++) {
        struct range r = rs[i];
        struct range c = cs[i];
        for(k1 = r.start; k1 <= r.end; k1++) {
            for(k2 = c.start; k2 <= c.end; k2++) {
                map[k1][k2] = ENUM_WALL;
            }
        }
    }
    return;
}

void display(char map[][COMP_COL_MAX+2], struct point2d size) {
    int i, j;
    for(i = 1; i <= size.row; i++) {
        for(j = 1; j <= size.col; j++) {
            printf(" %d", map[i][j]);
        }
        putchar('\n');
    }
    return;
}

struct point2d dist[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

static struct point2d queue[(COMP_COL_MAX+1)*(COMP_ROW_MAX+1)];
static int qstart = 0;
static int qend = 0;

void reset_queue(void) {
    qstart = qend = 0;
}

void enqueue(struct point2d p) {
    queue[qstart++] = p;
}

struct point2d dequeue(void) {
    return queue[qend++];
}

int is_empty(void) {
    return qstart == qend;
}

void bfs(char map[][COMP_COL_MAX+2], struct point2d start) {
    reset_queue();
    enqueue(start);
    int i;
    while(!is_empty()) {
        struct point2d p = dequeue();
        // it's necessary!
        if(map[p.row][p.col] == ENUM_WALL) continue;
        map[p.row][p.col] = ENUM_WALL;
        for(i = 0; i < 4; i++) {
            struct point2d np = {
                p.row + dist[i].row,
                p.col + dist[i].col
            };
            if(map[np.row][np.col] == ENUM_WALL) continue;
            enqueue(np);
        }
    }
    return;
}

int main(void) {
    int row, col;
    get_int2(&col, &row);
    // 1-indexed
    row++; col++;
    // [0, row) -> [0, row]
    // [0, col) -> [0, col]
    row--; col--;
    int num = get_int();
    int i, j;
    static struct range rs[NUM_MAX];
    static struct range cs[NUM_MAX];

    for(i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        get_int4(&x1, &y1, &x2, &y2);
        // 0-indexed -> 1-indexed for 2d-mapping
        x1++; y1++; x2++; y2++;
        // [x1, x2) -> [x1, x2]
        // [y1, y2) -> [y1, y2)
        x2--; y2--;
        rs[i] = (struct range){y1, y2};
        cs[i] = (struct range){x1, x2};
    }

    struct point2d size = {
        compress(rs, num, row),
        compress(cs, num, col),
    };

    static char map[COMP_ROW_MAX+2][COMP_COL_MAX+2];
    create_map(map, rs, cs, num, size);

#ifdef DEBUG
    printf("row: %d, col: %d\n", size.row, size.col);
    display(map, size);
#endif

    // bfs
    int64_t cnt = 0;
    for(i = 1; i <= size.row; i++) {
        for(j = 1; j <= size.col; j++) {
            if(map[i][j] == ENUM_PATH) {
                struct point2d start = {i, j};
                bfs(map, start);
                cnt++;
            }
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
