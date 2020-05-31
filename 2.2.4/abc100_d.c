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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int64_t *a1, int64_t *a2, int64_t *a3) {
  scanf("%lld %lld %lld", a1, a2, a3);
  return 0;
}

struct cake {
    int64_t beauty;
    int64_t tastiness;
    int64_t popularity;
};

#define NUM_MAX 1000

int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 < aa2) return 1;
    if(aa1 == aa2) return 0;
    return -1;
}

int64_t calc(struct cake *cs, int num, int *signs, int selects) {
    static int64_t arr[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        arr[i] = cs[i].beauty * signs[0] + 
            cs[i].tastiness * signs[1] +
            cs[i].popularity * signs[2];
    }
    qsort(arr, num, sizeof(int64_t), desc);
    int64_t ans = 0;
    for(i = 0; i < selects; i++) {
        ans += arr[i];
    }
    return ans;
}

int main(void) {
    int num, selects;
    struct cake cakes[NUM_MAX];
    get_int2(&num, &selects);
    int i, j, k;
    for(i = 0; i < num; i++) {
        int64_t p1, p2, p3;
        get_int3(&p1, &p2, &p3);
        cakes[i] = (struct cake){p1, p2, p3};
    }

    int64_t ans = 0;
    for(i = -1; i <= 1; i+=2) {
        for(j = -1; j <= 1; j+=2) {
            for(k = -1; k <= 1; k+=2) {
                int signs[3] = {i, j, k};
                int64_t res = calc(cakes, num, signs, selects);
                ans = max(res, ans);
            }
        }
    }
    printf("%lld\n", ans);
}
