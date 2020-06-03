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

#define NUM_MAX 100

enum type {
    TYPE_WHITE = '.',
    TYPE_BLACK = '#',
};

int main(void) {
    int whites, blacks;
    get_int2(&whites, &blacks);
    static char map[NUM_MAX][NUM_MAX];
    whites--; blacks--;
    memset(map, TYPE_WHITE, NUM_MAX*NUM_MAX);
    memset(map, TYPE_BLACK, NUM_MAX*(NUM_MAX/2));

    int row, col;
white_dot:
    for(row = 0; row < (NUM_MAX/2)-1; row+=2) {
        for(col = 0; col < NUM_MAX; col+=2) {
            if(whites<=0) goto black_dot;
            map[row][col] = TYPE_WHITE;
            whites--;
        }
    }

black_dot:
    for(row = (NUM_MAX/2)+1; row < NUM_MAX; row+=2) {
        for(col = 0; col < NUM_MAX; col+=2) {
            if(blacks<=0) break;
            map[row][col] = TYPE_BLACK;
            blacks--;
        }
    }

    printf("%d %d\n", NUM_MAX, NUM_MAX);
    for(row = 0; row < NUM_MAX; row++) {
        for(col = 0; col < NUM_MAX; col++) {
            putchar(map[row][col]);
        }
        putchar('\n');
    }
    return 0;
}
