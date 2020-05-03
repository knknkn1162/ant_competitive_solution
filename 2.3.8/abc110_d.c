#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 30

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

#define LEN_MAX 100000
#define MAP_MAX 100
#define FACTORIAL_MAX (MAP_MAX + LEN_MAX)
#define DIVISOR 1000000007

static uint64_t factorial[FACTORIAL_MAX+1];
static uint64_t inv_factorial[FACTORIAL_MAX+1];

struct pair {
    int x;
    int y;
};

struct pair gcdext(int a, int b) {
    if(a==0) return (struct pair){0, 1};
    struct pair p = gcdext(b%a, a);
    return (struct pair){p.y - b/a*p.x, p.x};
}

void init_combi(int n) {
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    int i;
    for(i = 2; i <= n; i++) {
        factorial[i] = (factorial[i-1] * i) % DIVISOR;
        struct pair p = gcdext(i, DIVISOR);
        // p.x maybe negative
        int inv = (p.x + DIVISOR) % DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1] * inv) % DIVISOR;
    }
    return;
}
uint64_t calc_combi(int num, int r) {
    uint64_t ans = 1;
    ans = (ans * factorial[num])%DIVISOR;
    ans = (ans * inv_factorial[num-r])%DIVISOR;
    ans = (ans * inv_factorial[r])%DIVISOR;
    return ans;
}

uint64_t calc_homo(int kinds, int num) {
    return calc_combi(kinds+num-1, num);
}

int main(void) {
    int len, orig;
    int i, j;
    get_int2(&len, &orig);
    int orig_2 = (int)sqrt(0.5 + orig);

    // find prime in orig
    int cur = 2;
    //static int prime[MAP_MAX];
    static int cnt[MAP_MAX];
    int midx = 0;
    while(1) {
        if(orig==1) { midx++; break; }
        if(cur > orig_2) {
            cnt[midx++] = 1;
            break;
        }
        if(orig%cur) {
            if(cnt[midx]) midx++;
            cur++;
            continue;
        }
        orig /= cur;
        //prime[midx] = cur;
        cnt[midx]++;
    }
#ifdef DEBUG
    for(i = 0; i < midx; i++) {
        printf("%d ", cnt[i]);
    }
    putchar('\n');
#endif
    init_combi(len+100);

    uint64_t ans = 1;
    for(i = 0; i < midx; i++) {
        ans = (ans * calc_homo(len, cnt[i])) % DIVISOR;
    }

    printf("%d\n", (int)ans);
    return 0;
}
