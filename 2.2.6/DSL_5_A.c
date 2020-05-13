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

#define TIME_MAX 100000

int main(void) {
    int num, limit;
    get_int2(&num, &limit);
    static int map[TIME_MAX+1];
    int i;
    for(i = 0; i < num; i++) {
        int in, out;
        get_int2(&in, &out);
        map[in]++;
        map[out]--;
    }

    int ans = map[0];
    for(i = 1; i <= limit; i++) {
        map[i] += map[i-1];
        ans = max(ans, map[i]);
    }

    printf("%d\n", ans);
    return 0;
}
