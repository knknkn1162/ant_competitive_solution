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

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define ROW_MAX 2000
#define COL_MAX 2000

int main(void) {
    static char map[ROW_MAX+2][COL_MAX+2];

    int row, col;
    get_int2(&row, &col);
    int i, j;
    for(i = 1; i <= row; i++) {
        get_str(&map[i][1], col);
        for(j = 1; j <= col; j++) {
            map[i][j] = (map[i][j] == '.');
        }
    }

    static int row_cnt[ROW_MAX+2][COL_MAX+2];
    int k, right;
    for(i = 1; i <= row; i++) {
        int left = 0;
        int cnt = 0;
        for(right = 1; right <= col+1; right++) {
            if(map[i][right]) {
                cnt++;
                continue;
            }
            for(k = left+1; k < right; k++) {
                row_cnt[i][k] = cnt;
            }
            left = right;
            cnt = 0;
        }
    }

    static int col_cnt[ROW_MAX+2][COL_MAX+2];
    for(j = 1; j <= col; j++) {
        int left = 0;
        int cnt = 0;
        for(right = 1; right <= row+1; right++) {
            if(map[right][j]) {
                cnt++;
                continue;
            }
            for(k = left+1; k < right; k++) {
                col_cnt[k][j] = cnt;
            }
            left = right;
            cnt = 0;
        }

    }

    int mmax = 0;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            if(!map[i][j]) continue;
#ifdef DEBUG
            printf("%d %d\n", row_cnt[i][j], col_cnt[i][j]);
#endif
            int total = row_cnt[i][j] + col_cnt[i][j] - 1;
            mmax = max(total, mmax);
        }
    }
    printf("%d\n", mmax);
    return 0;
}
