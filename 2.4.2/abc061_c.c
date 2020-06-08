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

#define NUM_MAX 100000

int main(void) {
    int num;
    static int64_t map[NUM_MAX+1];
    int64_t k;
    scanf("%d %lld", &num, &k);
    int i;
    for(i = 0; i < num; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a] += b;
    }

    int64_t sum = 0;
    for(i = 1; i <= NUM_MAX; i++) {
        sum += map[i];
        if(sum >= k) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
