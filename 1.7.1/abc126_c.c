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

#define POWER_MAX 20

int main(void) {
    int num, llimit;
    get_int2(&num, &llimit);

    static int power2[POWER_MAX];
    power2[0] = 1;
    int i = 0;
    for(i = 1; i < POWER_MAX; i++) {
        power2[i] = power2[i-1] * 2;
    }

    static int map[POWER_MAX];
    for(i = 1; i <= num; i++) {
        int point = i;
        int cnt = 0;
        while(point < llimit) {
            cnt++;
            point *= 2;
        }
        map[cnt]++;
#ifdef DEBUG
        printf("%d -> %d\n", i, cnt);
#endif
    }

    double ans = 0;
    for(i = 0; i < POWER_MAX; i++) {
        ans += 1.0 / num * (1.0/power2[i]) * map[i];
    }
    printf("%.10lf\n", ans);
    return 0;
}
