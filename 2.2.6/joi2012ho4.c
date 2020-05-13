#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define BUF_SIZE 40
 
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
 
int get_int3(int *a1, int *a2, int *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d", a1, a2, a3);
#else
#error
#endif
  return 0;
}
 
struct point2d {
    int row;
    int col;
};
 
struct triangle {
    struct point2d start;
    int size;
};
 
#define NAILS_MAX 5000
#define RUBBERS_MAX 500000
 
int main(void) {
    int side, rubbers;
    get_int2(&side, &rubbers);
 
    int i;
    static int diff3[NAILS_MAX+4][NAILS_MAX+4] = {0};
    for(i = 0; i < rubbers; i++) {
        struct point2d start;
        int size;
        get_int3(&start.row, &start.col, &size);
        diff3[start.row][start.col]++; diff3[start.row][start.col+1]--;
        diff3[start.row+size+1][start.col]--; diff3[start.row+size+2][start.col+1]++;
        diff3[start.row+size+2][start.col+size+2]--; diff3[start.row+size+1][start.col+size+2]++;
#ifdef DEBUG
        putchar('\n');
        for(k = 1; k <= side+2; k++) {
            for(j = -side-2; j <= side+2; j++) {
                printf("%d ", j>=0 ? diff3[k][j] : 0);
            }
            putchar('\n');
        }
#endif
    }
 
    int ans = 0;
    int row, col, pos;
 
    // diff3 -> diff2
    // (1,1) (2,2) (3,3)..
    // (2,1) (3,2) ..
    for(pos = 0; pos <= side+2; pos++) {
        struct point2d start = {pos, 1};
        int c = 0;
        for(i = 0; i <= side+2-pos; i++) {
            struct point2d ns = {start.row+i, start.col+i};
            diff3[ns.row][ns.col] += c;
            c = diff3[ns.row][ns.col];
        }
    }
 
    // diff2 -> diff1 start:
    // (2,1) (2,2)-->
    for(row = 1; row <= side+2; row++) {
        int c = 0;
        for(col = 1; col <= row; col++) {
#ifdef DEBUG
            printf("pos: (%d, %d)\n", row, col);
#endif
            diff3[row][col] += c;
            c = diff3[row][col];
        }
    }
 
    // diff1 -> diff0(restore)
    // (1,1), (2,1)..
    // (2,2), (3,2)..
    for(col = 1; col <= side; col++) {
        int c = 0;
        for(row = col; row <= side; row++) {
#ifdef DEBUG
            printf("pos: (%d, %d)\n", row, col);
#endif
            diff3[row][col] += c;
            c = diff3[row][col];
        }
    }
 
    for(row = 1; row <= side; row++) {
        for(col = 1; col <= row; col++) {
#ifdef DEBUG
            printf("(%d, %d) -> %d\n", row, col, diff3[row][col]);
#endif
            if(diff3[row][col]) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
