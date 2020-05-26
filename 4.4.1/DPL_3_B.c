#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define min3(a,b,c) min(min(a,b),c)

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(char *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    return 0;
}

#define NUM_MAX 1400

struct rect {
    int height;
    int width;
};

int main(void) {
    int height, width;
    get_int2(&height, &width);
    static char mat[NUM_MAX+1][NUM_MAX+1];
    int i, j;
    for(i = 1; i <= height; i++) {
        fget_array(&mat[i][1], width);
        // 0: dirty, 1: clean(usable)
        for(j = 1; j <= width; j++) mat[i][j] = 1-mat[i][j];
    }

    static int hist[NUM_MAX+1][NUM_MAX+1];
    for(i = 1; i <= height; i++) {
        for(j = 1; j <= width; j++) {
            if(!mat[i][j]) {
                hist[i][j] = 0;
            } else {
                hist[i][j] = hist[i-1][j] + 1;
            }
        }
    }

    static int seq_max[NUM_MAX+1];
    int k;
    for(i = 1; i <= height; i++) {
        int cnt[NUM_MAX+1] = {0};
        for(j = 1; j <= width; j++) {
            for(k = 1; k <= hist[i][j]; k++) {
                cnt[k]++;
                seq_max[k] = max(seq_max[k], cnt[k]);
            }
            for(k = hist[i][j]+1; k <= height; k++) cnt[k] = 0;
        }
    }

    int ans = 0;
    for(i = 1; i <= height; i++) {
        ans = max(ans, seq_max[i]*i);
    }

    printf("%d\n", ans);

    return 0;
}
