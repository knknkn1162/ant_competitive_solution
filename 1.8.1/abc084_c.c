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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

#define NUM_MAX 500

struct train {
    int duration;
    int start;
    int interval;
};

int main(void) {
    int num = get_int();

    static struct train trains[NUM_MAX];
    int i;
    for(i = 0; i < num-1; i++) {
        int c, s, f;
        get_int3(&c, &s, &f);
        trains[i] = (struct train){c, s, f};
    }

    static int ans[NUM_MAX];
    int start;
    for(start = num-2; start >= 0; start--) {
        int elapse = 0;
        for(i = start; i < num-1; i++) {
            struct train t = trains[i];
            elapse = max(t.start, elapse);
            elapse = ((elapse-1)/t.interval+1)*t.interval;
            elapse += t.duration;
#ifdef DEBUG
            printf("start: %d -> %d\n", start, elapse);
#endif
        }
        ans[start] = elapse;
    }

    for(i = 0; i < num; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
