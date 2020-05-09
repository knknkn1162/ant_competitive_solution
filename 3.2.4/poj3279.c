#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define ROWS_MAX 15
#define COLS_MAX 15

#define BUF_SIZE (ROWS_MAX+10)

int d4[4][2] = {
    // {0, 1},
    {0, 0},
    {0, -1},
    {1, 0},
    {-1, 0},
};
#define INF 100000

int main(void) {
    int rows, cols;
    static char mat[ROWS_MAX+1][COLS_MAX+1];
    static char ans[ROWS_MAX+2][COLS_MAX+2];
    static int buf[BUF_SIZE];
    get_int2(&rows, &cols);

    int i, j;
    for(i = 1; i <= rows; i++) {
        fget_array(&buf[1], cols);
        for(j = 1; j <= cols; j++) {
            mat[i][j] = buf[j];
        }
    }

    int pat, bit, col, row;
    static char res[ROWS_MAX+2][COLS_MAX+2];
    int ans_cnt = INF;
    for(pat = 1; pat <= (1<<rows); pat++) {
        int pat2 = (pat) % (1<<rows);
        int cnt = 0;
        memset(res, 0, (ROWS_MAX+2)*(COLS_MAX+2));
        // col = 1
        for(bit = 0; bit < rows; bit++) {
            if(!(pat2 & (1<<bit))) continue;
            res[bit+1][1] = 1;
        }
        // col = 2~
        int flag = 1;
        for(col = 2; col <= cols+1; col++) {
            char status[ROWS_MAX+2] = {0};
            for(row = 1; row <= rows; row++) {
                status[row] = mat[row][col-1];
            }
            for(row = 1; row <= rows; row++) {
                // what's state on [row][col-1]?
                for(i = 0; i < 4; i++) {
                    status[row] = (status[row]+res[row+d4[i][0]][col-1+d4[i][1]])%2;
                }
#ifdef DEBUG
                printf("[%d]: status[%d][%d] = %d\n", pat2, row, col, status[row]);
#endif
                if(status[row] == 1) {
                    if(col == cols+1) {
                        flag = 0;
                        break;
                    }
                    res[row][col] = 1;
                }
            }
        }
        if(flag) {
#ifdef DEBUG
            printf("%d\n", pat2);
            for(i = 1; i <= rows; i++) {
                for(j = 1; j <= cols; j++) {
                    printf("%d%c", res[i][j], j == cols ? '\n' : ' ');
                }
            }
#endif
            for(i = 1; i <= rows; i++) {
                for(j = 1; j <= cols; j++) {
                    cnt += res[i][j];
                }
            }
            if(ans_cnt > cnt) {
                ans_cnt = cnt;
                memcpy(ans, res, (ROWS_MAX+2)*(COLS_MAX+2));
            }
        }
    }
    if(ans_cnt == INF) {
        printf("IMPOSSIBLE\n");
    } else {
        for(i = 1; i <= rows; i++) {
            for(j = 1; j <= cols; j++) {
                printf("%d%c", ans[i][j], j == cols ? '\n' : ' ');
            }
        }
    }

    return 0;
}
