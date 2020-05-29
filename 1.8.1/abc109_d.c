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
int fget_array(char *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int n;
        scanf("%d", &n);
        arr[i] = n;
    }
    return 0;
}

#define ROW_MAX 500
#define COL_MAX 500
struct point2d {
    int row;
    int col;
};

static struct point2d stack[ROW_MAX*COL_MAX];
static int sidx = 0;
struct point2d pop(void) {
    return stack[--sidx];
}
void push(struct point2d p) {
    stack[sidx++] = p;
}

#define ANS_MAX (ROW_MAX*COL_MAX+50)
struct operation {
    struct point2d cur;
    struct point2d next;
};

int dir4[][2] = {
    {1, 0},
    {0, 1},
};


int main(void) {
    int rs, cs;
    get_int2(&rs, &cs);
    static char map[ROW_MAX+2][COL_MAX+2];
    memset(map, 0xff, (ROW_MAX+2)*(COL_MAX+2));
    int i, j, k;
    for(i = 1; i <= rs; i++) {
        fget_array(&map[i][1], cs);
    }

    int oidx = 0;
    static struct operation ops[ANS_MAX];
    // make coins rightbottom
    for(i = 1; i <= rs; i++) {
        for(j = 1; j <= cs; j++) {
            struct point2d p = {i, j};
            if(!(map[i][j]%2)) continue;
            for(k = 0; k < 2; k++) {
                struct point2d np = {i+dir4[k][0], j+dir4[k][1]};
                if(!map[p.row][p.col]) continue;
                if(map[np.row][np.col] < 0) continue;;
                ops[oidx++] = (struct operation){ p, np };
                map[p.row][p.col] -= 1;
                map[np.row][np.col] += 1;
                break;
            }
        }
    }

    printf("%d\n", oidx);
    for(i = 0; i < oidx; i++) {
        printf("%d %d %d %d\n",
            ops[i].cur.row, ops[i].cur.col,
            ops[i].next.row, ops[i].next.col
        );
    }

    return 0;

}
