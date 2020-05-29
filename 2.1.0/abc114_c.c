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

static int map[10];
static int valid[3] = {3, 5, 7};
int traverse(int64_t cur, int64_t limit) {
    if(cur > limit) return 0;
    int ans = 0;
    int i;
    int flag = 1;
    for(i = 0; i < 3; i++) {
        int d = valid[i];
        if(!map[d]) flag = 0;
        map[d]++;
        ans += traverse(cur*10 + d, limit);
        map[d]--;
    }
    return ans + flag;
}

int main(void) {
    int num = get_int();
    int ans = traverse(0, num);
    printf("%d\n", ans);
    return 0;
}
