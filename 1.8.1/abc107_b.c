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

enum type {
    ENUM_WHITE = '.',
    ENUM_BLACK = '#'
};

int main(void) {
    int row, col;
    static char map[ROW_MAX][COL_MAX+10];
    static char deleted[ROW_MAX][COL_MAX+10];
    get_int2(&row, &col);
    int i, j;
    for(i = 0; i < row; i++) {
        get_str(&map[i][0], COL_MAX);
    }

    for(i = 0; i < row; i++) {
        int flag = 1;
        for(j = 0; j < col; j++) {
            if(map[i][j] == ENUM_BLACK) {flag = 0; break;}
        }
        if(!flag) continue;
        for(j = 0; j < col; j++) deleted[i][j] = 1;
    }

    for(j = 0; j < col; j++) {
        int flag = 1;
        for(i = 0; i < row; i++) {
            if(map[i][j] == ENUM_BLACK) {flag = 0; break;}
        }
        if(!flag) continue;
        for(i = 0; i < row; i++) deleted[i][j] = 1;
    }

    // presentation
    for(i = 0; i < row; i++) {
        int flag = 0;
        for(j = 0; j < col; j++) {
            if(!deleted[i][j]) {putchar(map[i][j]); flag = 1;}
        }
        if(flag) putchar('\n');
    }

    return 0;
}
