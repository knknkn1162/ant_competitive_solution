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

struct drink {
    int price;
    int stock;
};

int asc_by_price(const void *a1, const void *a2) {
    struct drink *d1 = (struct drink*)a1;
    struct drink *d2 = (struct drink*)a2;
    return d1->price - d2->price;
}

#define NUM_MAX 100000

int main(void) {
    int num, llimit;
    static struct drink drinks[NUM_MAX];
    get_int2(&num, &llimit);
    int i;
    for(i = 0; i < num; i++) {
        get_int2(&drinks[i].price, &drinks[i].stock);
    }
    qsort(drinks, num, sizeof(struct drink), asc_by_price);

    int64_t cost = 0;
    for(i = 0; i < num; i++) {
        if(llimit <= 0) break;
        int n = min(llimit, drinks[i].stock);
        cost += (int64_t)drinks[i].price * n;
        llimit -= n;
    }
    printf("%lld\n", cost);
    return 0;
}
