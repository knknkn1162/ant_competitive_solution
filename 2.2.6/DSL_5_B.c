#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

#define X_MAX 1000
#define Y_MAX 1000

int main(void) {
    int num = get_int();
    int i, j;

    static int map[X_MAX+1][Y_MAX+1];

    for(i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        get_int4(&x1, &y1, &x2, &y2);
        map[x1][y1]++;
        map[x1][y2]--;
        map[x2][y1]--;
        map[x2][y2]++;
    }

    for(i = 0; i <= X_MAX; i++) {
        for(j = 1; j <= Y_MAX; j++) {
            map[i][j] += map[i][j-1];
        }
    }
    for(i = 1; i <= X_MAX; i++) {
        for(j = 0; j <= Y_MAX; j++) {
            map[i][j] += map[i-1][j];
        }
    }

    int ans = 1;
    for(i = 0; i < X_MAX; i++) {
        for(j = 0; j < Y_MAX; j++) {
            ans = max(ans, map[i][j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
