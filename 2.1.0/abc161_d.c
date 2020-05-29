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

#define NUM_MAX 500000
#define INF (int64_t)(1e+10)
static int64_t ans[NUM_MAX];
static int aidx = 0;
void traverse(int64_t num) {
    int i;
    if(num >= INF) return;
    ans[aidx++] = num;
    for(i = 0; i <= 9; i++) {
        int64_t new = num*10+i;
        if(labs(num%10-i) <= 1) {
            traverse(new);
        }
    }
    return;
}

int asc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    return (aa1>aa2)*2-1;
}

int main(void) {
    int k = get_int();
    int i;
    for(i = 1; i <= 9; i++) {
        traverse(i);
    }
    qsort(ans, aidx, sizeof(int64_t), asc);
    printf("%lld\n", ans[k-1]);
    return 0;
}
