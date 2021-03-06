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

int get_int2(int64_t *a1, int *a2) {
  scanf("%lld %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int64_t *a2, int *a3) {
  scanf("%d %lld %d", a1, a2, a3);
  return 0;
}

struct monster {
    int64_t pos;
    int hp;
};

int asc_by_pos(const void *a1, const void *a2) {
    struct monster *ma1 = (struct monster*)a1;
    struct monster *ma2 = (struct monster*)a2;
    return ma1->pos - ma2->pos;
}

#define NUM_MAX 200000
#define NUM2_MAX (1<<18)
#define ROOT_NODE 1
#define INF ((int64_t)(3e+9)+1)

int main(void) {
    int num, attack;
    int64_t range;
    static struct monster mons[NUM_MAX+1];
    get_int3(&num, &range, &attack);
    range *= 2;
    int num2 = 1;
    while(num > num2) num2 *= 2;

    int i;
    for(i = 0; i < num; i++) {
        get_int2(&mons[i].pos, &mons[i].hp);
    }
    mons[num] = (struct monster){INF, 0}; // guard
    qsort(mons, num, sizeof(struct monster), asc_by_pos);

    int left;
    int right = 0;
    int64_t ans = 0;
    static int64_t diff[NUM_MAX+1];
    static int64_t cum = 0;

    for(left = 0; left < num+1; left++) {
        cum += diff[left];
        if(left == right) { right++; }
        int64_t hp = mons[left].hp - cum * attack;
        if(hp <= 0) continue; // if no hit point, break;
        // ensure that mons[left] should be attacked
        for(;right < num+1; right++) {
            if(mons[left].pos + range < mons[right].pos) break;
        }
#ifdef DEBUG
        printf("[%d, %d)\n", left, right);
#endif
        // attack
        int64_t cnt = (hp-1)/attack + 1;

        // left has already searched
        diff[left+1] += cnt;
        diff[right] -= cnt;
        ans += cnt;
    }
    printf("%lld\n", ans);

    return 0;
}
