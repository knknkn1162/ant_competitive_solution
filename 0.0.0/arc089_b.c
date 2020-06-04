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

struct pair {
    int blacks;
    int whites;
};

int main(void) {
    int num, pat;
    get_int2(&num, &pat);

    int i;
    static struct pair cnt[K_MAX*2][K_MAX*2];
    for(i = 0; i < num; i++) {
        int x, y;
        char color;
        get_int3(&x, &y, &color);
        x %= (pat*2);
        y %= (pat*2);
        if(color == ENUM_WHITE) {
            cnt[x][y].whites++;
        } else {
            cnt[x][y].blacks++;
        }
    }

    int move_x, move_y;
    int ans = 0;
    int x, y;
    for(move_x = 0; move_x < pat; move_x++) {
        for(move_y = 0; move_y < pat; move_y++) {
            int res = 0;
            for(x = 0; x < pat*2; x++) {
                for(y = 0; y < pat*2; y++) {
                    struct point2d np = {
                        (x-move_x+pat*2)%(2*pat),
                        (y-move_y+pat*2)%(2*pat)
                    };
                    int is_black = (np.x+np.y)%(4*pat) >= 2*pat;
                    res += is_black ? cnt[x][y].blacks : cnt[x][y].whites;
                }
            }
#ifdef DEBUG
            printf("%d %d -> %d\n", move_x, move_y, res);
#endif
            ans = max(ans, res);
        }
    }

    printf("%d\n", ans);
    return 0;
}
