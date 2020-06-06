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

void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

struct pair3 {
    int64_t a;
    int64_t b;
    int64_t c;
};

#define INF (1e+9)

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
int64_t calc_diff(struct pair3 p) {
    return max3(p.a, p.b, p.c) - min3(p.a, p.b, p.c);
}

int cut_hw(struct pair3 *out, int height, int width) {
    // height is bigger
    int64_t hlow = height/3;
    int64_t hhigh = height/3 + 1;
    int64_t wlow = width/2;
    int64_t wrem = width - width/2;
    int cidx = 0;
    int64_t hrem = height-hlow;
    out[cidx++] = (struct pair3){hlow*width, wlow*hrem, wrem*hrem};
    hrem = height - hhigh;
    out[cidx++] = (struct pair3){hhigh*width, wlow*hrem, wrem*hrem};
    return cidx;
}


int main(void) {
    int height, width;
    get_int2(&height, &width);
    int64_t ans = INF;
    if(height < width) swap(&height, &width);
    // cut the same way
    ans = (height%3==0 || width%3==0) ? 0 : width;

    struct pair3 cands[10];
    int cidx = 0;
    cidx += cut_hw(cands, height, width);
    cidx += cut_hw(&cands[cidx], width, height);

    int i;
    for(i = 0; i < cidx; i++) {
#ifdef DEBUG
        printf("%d, %d, %d, %d\n", cands[i].a, cands[i].b, cands[i].c, calc_diff(cands[i]));
#endif
        ans = min(ans, calc_diff(cands[i]));
    }
    printf("%lld\n", ans);
    return 0;
}
