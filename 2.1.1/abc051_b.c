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

int main(void) {
    int ulimit, sum;
    get_int2(&ulimit, &sum);

    int i, j;
    int cnt = 0;
    for(i = 0; i <= ulimit; i++) {
        for(j = 0; j <= ulimit; j++) {
            int rem = sum-i-j;
            if(rem >= 0 && rem <= ulimit) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
