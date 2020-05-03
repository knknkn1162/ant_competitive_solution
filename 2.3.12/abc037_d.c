#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define ROW_MAX 1000
#define COL_MAX ROW_MAX
#define BUF_SIZE (ROW_MAX*11+50)

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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

static int dist[][2] = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
};

struct pair {
    int row;
    int col;
};

#define DIVISOR 1000000007


static int arr[ROW_MAX+2][COL_MAX+2];
static int out_deg[ROW_MAX+2][COL_MAX+2];
static char check[ROW_MAX+2][COL_MAX+2];
static uint64_t count[ROW_MAX+2][COL_MAX+2];
void dfs(struct pair p, uint64_t cnt) {
    int k;
    count[p.row][p.col] = (count[p.row][p.col] + cnt) % DIVISOR;
#ifdef DEBUG
    printf("count[%d][%d] = %llu\n", p.row, p.col, count[p.row][p.col]);
#endif
    if(out_deg[p.row][p.col]) return;
    check[p.row][p.col] = 1;
    for(k = 0; k < 4; k++) {
        struct pair np = {
            p.row + dist[k][0],
            p.col + dist[k][1],
        };
        if(arr[p.row][p.col] >= arr[np.row][np.col]) continue;
        out_deg[np.row][np.col]--;
        dfs(np, count[p.row][p.col]);
    }
}

int main(void) {
    int row, col;
    get_int2(&row, &col);

    int i, j, k;
    for(i = 1; i <= row; i++) {
        fget_array(&arr[i][1], col);
    }

    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            count[i][j] = 1;
            struct pair p = {i, j};
            for(k = 0; k < 4; k++) {
                struct pair np = {
                    p.row + dist[k][0],
                    p.col + dist[k][1]
                };
                if(arr[i][j] < arr[np.row][np.col]) {
                    out_deg[np.row][np.col]++;
                }
            }
        }
    }

    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            if(!out_deg[i][j] && !check[i][j]) {
                struct pair p = {i,j};
                dfs(p, 0);
            }
        }
    }

    uint64_t ans = 0;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            ans = (ans + count[i][j])%DIVISOR;
        }
    }
    printf("%d\n", (int)ans);
    return 0;
}
