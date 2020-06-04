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

int get_int3(int *a1, int *a2, char *a3) {
  scanf("%d %d %c", a1, a2, a3);
  return 0;
}

struct point2d {
    int x;
    int y;
};

#define NUM_MAX 100000
#define K_MAX 1000

enum color {
    ENUM_WHITE = 'W',
    ENUM_BLACK = 'B'
};

int main(void) {
    int num, pat;
    get_int2(&num, &pat);

    int i;
    static int cnt[K_MAX*2][K_MAX*2];
    for(i = 0; i < num; i++) {
        int x, y;
        char color;
        get_int3(&x, &y, &color);
        x = x % (pat*2);
        y = y % (pat*2);
        struct point2d np1 = {x%(pat*2), (y+pat)%(pat*2)};
        struct point2d np2 = {(x+pat)%(pat*2), y%(pat*2)};
        struct point2d np3 = {(x+pat)%(pat*2), (y+pat)%(pat*2)};
        if(color == ENUM_WHITE) {
            cnt[x][y]++;
            cnt[np3.x][np3.y]++;
        } else {
            cnt[np1.x][np1.y]++;
            cnt[np2.x][np2.y]++;
        }
    }

    int row, col;
#ifdef DEBUG
    for(row = 0; row < pat*2; row++) {
        for(col = 0; col < pat*2; col++) {
            printf(" %d", cnt[row][col]);
        }
        putchar('\n');
    }
#endif

    // calc cumulative sum of 2d
    static int cum_row[K_MAX*2+1][K_MAX*2+1];
    static int cum_col[K_MAX*2+1][K_MAX*2+1];
    static int cum[K_MAX*2+1][K_MAX*2+1];
    for(row = 1; row <= pat*2; row++) {
        for(col = 1; col <= pat*2; col++) {
            cum_row[row][col] = cum_row[row][col-1] + cnt[row-1][col-1];
        }
    }

    for(col = 1; col <= pat*2; col++) {
        for(row = 1; row <= pat*2; row++) {
            cum_col[row][col] = cum_col[row-1][col] + cnt[row-1][col-1];
        }
    }

    for(row = 1; row <= pat*2; row++) {
        for(col = 1; col <= pat*2; col++) {
            cum[row][col] = cum[row-1][col-1] + cum_col[row][col] + cum_row[row][col] - cnt[row-1][col-1];
        }
    }
#ifdef DEBUG
    printf("cum\n");
    for(row = 1; row <= pat*2; row++) {
        for(col = 1; col <= pat*2; col++) {
            printf(" %d", cum[row][col]);
        }
        putchar('\n');
    }
#endif

    int ans = 0;
    for(row = 0; row < pat; row++) {
        for(col = 0; col < pat; col++) {
            int res = cum[row+pat][col+pat] - cum[row][col+pat] - cum[row+pat][col] + cum[row][col];
            ans = max(ans, res);
            ans = max(ans, num-res);
        }
    }
    printf("%d\n", ans);
    return 0;
}
