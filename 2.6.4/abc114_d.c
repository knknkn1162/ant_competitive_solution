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

int divs[] = {3, 5, 15, 25, 75};
int traverse(int *prime_map, int idx, int val) {
    if(val==1) return 1;
    if(idx >= 100) return 0;
    int i;
    int ans = 0;
    ans += traverse(prime_map, idx+1, val);
    for(i = 0; i < 5; i++) {
        if(val%divs[i]) continue;
        int d = divs[i];
        if(prime_map[idx] >= d-1) {
            prime_map[idx] -= (d-1);
            ans += traverse(prime_map, idx+1, val/d);
            prime_map[idx] += (d-1);
        }
    }
    return ans;
}

#define TARGET_VAL 75
#define NUM_MAX 100
int main(void) {
    int num = get_int();
    static int prime_map[NUM_MAX+1];

    int i;
    for(i = 2; i <= num; i++) {
        int cur = i;
        int divisor = 2;
        while(cur>1) {
            if(cur%divisor) { divisor++; continue; }
            cur /= divisor;
            prime_map[divisor]++;
        }
    }

#ifdef DEBUG
    for(i = 2; i <= num; i++) printf(" %d", prime_map[i]);
    putchar('\n');
#endif

    int64_t ans = traverse(prime_map, 0, TARGET_VAL);

    printf("%lld\n", ans);
    return 0;
}
