#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int64_t *a2) {
  scanf("%d %lld", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100000
// 2**10 = 10**3
// 10**12 => 2**(10*4)
#define BIT_MAX 40

#define power2(bit) (1LL<<bit)

int main(void) {
    int num;
    int64_t ulimit;
    static int64_t arr[NUM_MAX];
    get_int2(&num, &ulimit);
    fget_array(arr, num);

    int i, bit;
    static int cnt[BIT_MAX+1];
    for(i = 0; i < num; i++) {
        for(bit = 0; bit <= BIT_MAX; bit++) {
            cnt[bit] += !!(arr[i] & (1LL<<bit));
        }
    }

    static int64_t max_ans[BIT_MAX+1];
    for(bit = 0; bit <= BIT_MAX; bit++) {
        int c = max(num-cnt[bit], cnt[bit]);
        max_ans[bit] += power2(bit)*c;
        if(bit>=1) max_ans[bit] += max_ans[bit-1];
    }
    int64_t cur = 0;
    int64_t ans = 0;
    for(bit = BIT_MAX; bit>= 0; bit--) {
        if(!(ulimit & power2(bit))) {
            // select 0 and continue
            cur += power2(bit)*cnt[bit];
        } else {
            // select 0 and break;
            if(bit>=1) ans = max(ans, cur + power2(bit)*cnt[bit] + max_ans[bit-1]);
            // select 1 and continue
            cur += power2(bit)*(num-cnt[bit]);
        }
#ifdef DEBUG
        printf("%d -> %lld vs ans: %lld\n", bit, cur, ans);
#endif
        ans = max(ans, cur);
    }
    printf("%lld\n", ans);
    return 0;
}
