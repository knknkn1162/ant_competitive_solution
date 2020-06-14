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

#define DIVISOR 1000000007
#define NUM_MAX 200000
// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

struct point2d {
    int row;
    int col;
};

struct pair {
    int x;
    int y;
};

struct pair gcdext(int a, int b) {
    if(a==0) { return (struct pair){0, 1}; }
    struct pair p = gcdext(b%a, a);
    return (struct pair){p.y - (b/a)*p.x, p.x};
}
static int64_t factorial[NUM_MAX+1];
static int64_t inv_factorial[NUM_MAX+1];
void init_combi(int size) {
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    int i;
    for(i = 2; i <= size; i++) {
        factorial[i] = (factorial[i-1] * i)%DIVISOR;
        struct pair p = gcdext(i, DIVISOR);
        int inv = (p.x + DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1] * inv)%DIVISOR;
    }
    return;
}

int64_t calc_combi(int n, int k) {
    if(k > n) return 0;
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    return ans;
}


int64_t calc_routes(struct point2d p1, struct point2d p2) {
    int rs = p2.row - p1.row;
    int cs = p2.col - p1.col;
    return calc_combi(rs+cs, rs);
}

int main(void) {
    int rows, cols;
    get_int2(&rows, &cols);
    // edge
    rows--; cols--;
    int a, b;
    get_int2(&a, &b);
    init_combi(rows+cols);

    int64_t ans = 0;
    // usually, calc_combi(rows-1+cols-1, cols-1)
    int r;
    struct point2d bp = (struct point2d){rows-a, b};
    for(r = 0; r <= bp.row; r++) {
        int64_t res = 1;
        // lefttop
        struct point2d start1 = (struct point2d){0, 0};
        struct point2d end1 = (struct point2d){r, bp.col};
        res = (res * calc_routes(start1, end1));
        // rows-i-i
        // rightbottom: rows-i, cols-b-1
        struct point2d start2;
        if(r == bp.row) {
            start2 = (struct point2d){r, bp.col};
        } else {
            start2 = (struct point2d){r, bp.col+1};
        }
        struct point2d end2 = (struct point2d){rows, cols};
        res = (res * calc_routes(start2, end2))%DIVISOR;
#ifdef DEBUG
        printf("topleft: (%d %d) -> (%d %d)  ",
            start1.row, start1.col,
            end1.row, end1.col
        );
        printf("bottomright: (%d %d) -> (%d %d)",
            start2.row, start2.col,
            end2.row, end2.col
        );
        printf(" -> %lld\n", res);
#endif
        ans = (ans + res)%DIVISOR;
    }
    printf("%d\n", (int)ans);
    return 0;
}
