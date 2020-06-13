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

struct point2d {
    int row;
    int col;
};

#define ROW_MAX 100000
#define COL_MAX 100000
#define NUM_MAX 100000

int main(void) {
    int rows, cols;
    get_int2(&rows, &cols);
    int sum = get_int();
    int num = get_int();

    int i;
    static int row_map[ROW_MAX+1];
    static int col_map[COL_MAX+1];
    static struct point2d points[NUM_MAX];
    for(i = 0; i < num; i++) {
        int r, c;
        get_int2(&r, &c);
        // 1-indexed -> 0-indexed
        r--; c--;
        points[i] = (struct point2d){r, c};
        row_map[r]++;
        col_map[c]++;
    }
    static int col_cntmap[NUM_MAX+1];
    for(i = 0; i < cols; i++) {
        int cnt = col_map[i];
        col_cntmap[cnt]++;
    }

    int64_t ans = 0;
    for(i = 0; i < rows; i++) {
        int row_cnt = row_map[i];
        int rem = sum-row_cnt;
        // If candy is not in this place: OK
        // If candy is in this place .. remove later
        if(rem>=0) ans += col_cntmap[rem];
    }

    for(i = 0; i < num; i++) {
        struct point2d p = points[i];
        int cnt = row_map[p.row] + col_map[p.col] - 1;
        if(cnt == sum) {
            ans++; // should be added
        } else if(cnt == sum-1) {
            ans--; // should be removed
        }
    }
    printf("%lld\n", ans);
    return 0;
}
