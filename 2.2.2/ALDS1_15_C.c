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

struct range {
    int start;
    int end;
};

#define NUM_MAX 100000

int asc_by_end(const void *a1, const void *a2) {
    struct range *ra1 = (struct range*)a1;
    struct range *ra2 = (struct range*)a2;
    return ra1->end - ra2->end;
}

int main(void) {
    int num = get_int();
    int i;
    static struct range rs[NUM_MAX];
    for(i = 0; i < num; i++) {
        get_int2(&rs[i].start, &rs[i].end);
    }

    qsort(rs, num, sizeof(struct range), asc_by_end);

    int cur_end = 0;
    int ans = 0;
    for(i = 0; i < num; i++) {
        if(rs[i].start <= cur_end) continue;
        ans++;
        cur_end = rs[i].end;
    }

    printf("%d\n", ans);
    return 0;
}
