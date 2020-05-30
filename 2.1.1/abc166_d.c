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

// 1000**5 - 999**5 = 4.99001e+12
#define NUM_MAX 1000

struct pair {
    int a;
    int b;
};

int main(void) {
    int64_t target = get_int();
    int a, b;
    struct pair ans = {0, 0};
    for(a = 0; a <= NUM_MAX; a++) {
        for(b = 0; b <= NUM_MAX; b++) {
            int64_t a5 = (int64_t)a*a*a*a*a;
            int64_t b5 = (int64_t)b*b*b*b*b;
            if(a5+b5 == target) {
                ans = (struct pair){a, -b};
                goto finish;
            }
            if(a5-b5==target) {
                ans = (struct pair){a, b};
                goto finish;
            }
        }
    }
finish:
    printf("%d %d\n", ans.a, ans.b);
    return 0;
}
