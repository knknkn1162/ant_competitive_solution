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

#define NUM_MAX 500
// max: 250000 * 1000
#define INF (1e+9)
#define COLOR_MAX 30
#define GROUPS 3

int calc(int group[][COLOR_MAX+1], int *cs, int ds[][COLOR_MAX+1], int colors) {
    int i, c;
    int disorder = 0;
    for(i = 0; i < GROUPS; i++) {
        for(c = 1; c <= colors; c++) {
            int before = c;
            int after = cs[i];
            disorder += ds[before][after] * group[i][c];
        }
    }
#ifdef DEBUG
    printf("%d, %d, %d -> %d\n", cs[0], cs[1], cs[2], disorder);
#endif
    return disorder;
}

int main(void) {
    int num, colors;
    get_int2(&num, &colors);
    // 1-indexed
    static int ds[COLOR_MAX+1][COLOR_MAX+1];
    static int mat[NUM_MAX+1][NUM_MAX+1];
    int i, j;
    for(i = 1; i <= colors; i++) {
        fget_array(&ds[i][1], colors);
    }

    for(i = 1; i <= num; i++) {
        fget_array(&mat[i][1], num);
    }

    static int group[3][COLOR_MAX+1];
    for(i = 1; i <= num; i++) {
        for(j = 1; j <= num; j++) {
            int c = mat[i][j];
            group[(i+j)%3][c]++;
        }
    }

    int c0, c1, c2; // c_(mod)
    int ans = INF;
    for(c0 = 1; c0 <= colors; c0++) {
        for(c1 = 1; c1 <= colors; c1++) {
            if(c0 == c1) continue;
            for(c2 = 1; c2 <= colors; c2++) {
                if(c1 == c2) continue;
                if(c0 == c2) continue;
                int cs[3] = {c0, c1, c2};
                int res = calc(group, cs, ds, colors);
                ans = min(ans, res);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
