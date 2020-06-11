#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

struct pair {
    int v1;
    int v2;
};

#define EDGE_MAX 10000

int main(void) {
    int num, k;
    get_int2(&num, &k);

    struct pair ps[EDGE_MAX];
    int pidx = 0;
    int mmax = (num-1)*(num-2)/2;
    if(k > mmax) {
        printf("-1\n");
        goto finish;
    }

    int i, j;
    int cnt = mmax;
    for(i = 1; i <= num-1; i++) {
        ps[pidx++] = (struct pair){i, num};
    }
    for(i = 1; i <= num-1; i++) {
        for(j = i+1; j <= num-1; j++) {
            if(cnt == k) goto exist;
            ps[pidx++] = (struct pair){i, j};
            cnt--;
        }
    }
exist:
    printf("%d\n", pidx);
    for(i = 0; i < pidx; i++) {
        printf("%d %d\n", ps[i].v1, ps[i].v2);
    }
finish:
    return 0;
}
