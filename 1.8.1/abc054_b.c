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

#define NUM_MAX 50

enum type {
    TYPE_WHITE = '.',
    TYPE_BLACK = '#',
};

struct point2d {
    int x;
    int y;
};

int main(void) {
    int as, bs;
    static char amap[NUM_MAX*2+1][NUM_MAX*2+1];
    static char bmap[NUM_MAX*2+1][NUM_MAX*2+1];
    // assume that as >= bs
    get_int2(&as, &bs);
    int flag = 0;
    int i, j;
    for(i = 0; i < as; i++) {
        get_str(amap[i], as);
    }
    for(i = 0; i < bs; i++) {
        get_str(bmap[i], bs);
    }

    int k1, k2;
    for(i = 0; i < as; i++) {
        for(j = 0; j < as; j++) {
            int ok = 1;
            for(k1 = 0; k1 < bs; k1++) {
                for(k2 = 0; k2 < bs; k2++) {
                    struct point2d ap = {i+k1, j+k2};
                    ok &= (amap[ap.x][ap.y] == bmap[k1][k2]);
                }
            }
            if(ok) { flag = 1; goto finish; }
        }
    }
finish:
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}
