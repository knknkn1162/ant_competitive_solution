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

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define ROW_MAX 100
#define COL_MAX 100

int dir[8][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

struct point2d {
    int x;
    int y;
};

int main(void) {
    int row, col;
    get_int2(&row, &col);
    static char map[ROW_MAX+2][COL_MAX+2];
    int i, j;
    for(i = 1; i <= row; i++) {
        get_str(&map[i][1], col);
        for(j = 1; j <= col; j++) {
            map[i][j] = (map[i][j] == '.');
        }
    }

    static char checked[ROW_MAX+2][COL_MAX+2];
    static char ans[ROW_MAX+2][COL_MAX+2];
    memset(ans, 0x01, (ROW_MAX+2)*(COL_MAX+2));
    int k;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            int flag = 1;
            if(map[i][j]) continue;
            for(k = 0; k < 8; k++) {
                struct point2d np = {
                    i + dir[k][0],
                    j + dir[k][1],
                };
                if(map[np.x][np.y]) { flag = 0; break; } 
            }
#ifdef DEBUG
            printf("%d %d -> %d\n", i, j, flag);
#endif
            if(!flag) continue;
            checked[i][j] = 1;
            ans[i][j] = 0;
            for(k = 0; k < 8; k++) {
                struct point2d np = {
                    i + dir[k][0],
                    j + dir[k][1],
                };
                checked[np.x][np.y] = 1;
            }
        }
    }
    // compare between checked and map
    int flag = 1;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            if(map[i][j]) continue;
            // wall & non-check
            if(!checked[i][j]) { flag = 0; break; }
        }
    }

    printf("%s\n", flag ? "possible" : "impossible");
    if(!flag) return 0;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            putchar(ans[i][j] ? '.' : '#');
        }
        putchar('\n');
    }
    return 0;
}
