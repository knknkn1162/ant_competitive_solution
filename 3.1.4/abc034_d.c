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

#define NUM_MAX 1000

struct solution {
    int whole;
    double salt;
};

#define LOOP_MAX 200

int desc(const void *a1, const void *a2) {
    return *(double*)a2 - *(double*)a1;
}

int judge(struct solution *sols, int size, int k, double key) {
    static double diff[NUM_MAX];
    memset(diff, 0, sizeof(double)*NUM_MAX);
    int i;
    for(i = 0; i < size; i++) {
        diff[i] = sols[i].salt - key*sols[i].whole / 100;
    }
    qsort(diff, size, sizeof(double), desc);
    double ans = 0;
    for(i = 0; i < k; i++) {
        ans += diff[i];
    }
#ifdef DEBUG
    printf("%d\n", ans);
#endif
    return (ans >= 0);
}

int main(void) {
    int num, k;
    struct solution sols[NUM_MAX];
    get_int2(&num, &k);
    int i;
    for(i = 0; i < num; i++) {
        int whole, p;
        get_int2(&whole, &p);
        double salt = (double)p * whole / 100;
        sols[i] = (struct solution){whole, salt};
    }

    double low = -1;
    double high = 101;
    int cnt = LOOP_MAX;
    while(cnt--) {
        double mid = (low + high)/2;
        // upper bound
        if(judge(sols, num, k, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    printf("%.8lf\n", low);
    return 0;
}
