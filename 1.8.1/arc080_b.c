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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define ROW_MAX 100
#define COL_MAX 100
#define NUM_MAX (ROW_MAX*COL_MAX)

int main(void) {
    int row, col;
    get_int2(&row, &col);
    int num = get_int();
    // 1-indexed
    static int arr[NUM_MAX];
    fget_array(&arr[1], num);
    int aidx = 1;

    int i, j;
    int norm[NUM_MAX];
    int rev[NUM_MAX];
    for(i = 0; i < col; i++) {
        norm[i] = i;
        rev[i] = col-i-1;
    }
    static int map[ROW_MAX][COL_MAX];
    for(i = 0; i < row; i++) {
        int *order = (i%2==0) ? norm : rev;
        for(j = 0; j < col; j++) {
            if(!arr[aidx]) aidx++;
            int jdx = order[j];
            map[i][jdx] = aidx;
            arr[aidx]--;
        }
    }

    // presentation
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d%c", map[i][j], j==(col-1) ? '\n' : ' ');
        }
    }
    return 0;
}
