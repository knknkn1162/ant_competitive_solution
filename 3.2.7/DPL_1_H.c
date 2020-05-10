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

int get_int2(int64_t *a1, int64_t *a2) {
  scanf("%lld %lld", a1, a2);
  return 0;
}

struct product {
    int64_t value;
    int64_t weight;
};

#define NUM_MAX 40
#define NUM_2_MAX (1<<20)

int asc(const void *a1, const void *a2) {
    struct product *pa1 = (struct product*)a1;
    struct product *pa2 = (struct product*)a2;
    if(pa1->weight == pa2->weight) {
        if(pa1->value < pa2->value) return -1;
        if(pa1->value == pa2->value) return 0;
        return 1;
    }
    if(pa1->weight < pa2->weight) return -1;
    return 1;
}

void enum_sum(struct product *ps, int offset, int size, struct product *out, int *idx) {
    int pat;
    int i;
    static struct product tmp[NUM_2_MAX];
    memset(tmp, NUM_2_MAX, sizeof(struct product)*(NUM_2_MAX));
    for(pat = 0; pat < (1<<size); pat++) {
        struct product p = {0, 0};
        for(i = 0; i < size; i++) {
            if(!(pat & (1<<i))) continue;
            p = (struct product){p.value+ps[i+offset].value, p.weight+ps[i+offset].weight};
        }
        tmp[pat] = p;
    }
    qsort(tmp, pat, sizeof(struct product), asc);
    tmp[pat++] = (struct product){0, INT64_MAX};
    int64_t prev = tmp[0].weight;
    int pidx = 0;
    int64_t value_max = 0;
    for(i = 0; i < pat; i++) {
        struct product p = tmp[i];
        if(prev != p.weight) {
            out[pidx++] = (struct product){value_max, prev};
            prev = p.weight;
        }
        value_max = max(value_max, p.value);
    }
    *idx = pidx;
    return;
}

int lower_bound(struct product *ps, int size, int64_t key) {
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        // upper bound
        if(ps[mid].weight <= key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(void) {
    int num;
    int64_t limit;
    get_int2((int64_t*)&num, &limit);
    int i;
    struct product prods[NUM_MAX];
    for(i = 0; i < num; i++) {
        get_int2(&prods[i].value, &prods[i].weight);
    }

    int num_2 = num/2;
    static struct product prods1[NUM_2_MAX];
    int pidx1 = 0;
    static struct product prods2[NUM_2_MAX];
    int pidx2 = 0;
    enum_sum(prods, 0, num_2, prods1, &pidx1);
    enum_sum(prods, num_2, num - num_2, prods2, &pidx2);
#ifdef DEBUG
    printf("%d %d\n", pidx1, pidx2);
#endif

    int64_t ans = 0;
    for(i = 0; i < pidx1; i++) {
        struct product p = prods1[i];
        if(p.weight > limit) continue;
        int idx = lower_bound(prods2, pidx2, limit-p.weight);
#ifdef DEBUG
        printf("%d, %lld -> %lld+%lld\n", idx, limit-p.weight, p.value, prods2[idx].value);
#endif
        ans = max(p.value + prods2[idx].value, ans);
    }
    printf("%lld\n", ans);

    return 0;
}
