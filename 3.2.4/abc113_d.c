#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

#define HEIGHT_MAX 100
#define WIDTH_MAX 8
#define DIVISOR 1000000007
#define PATTERN_MAX (1<<(WIDTH_MAX-1))

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void get_next(int pat, int size, int *out) {
    int i, bit;
    for(i = 0; i < size; i++) out[i] = i;
    for(bit = 0; bit < size-1; bit++) {
        if(!(pat & (1<<bit))) continue;
        // swap
        swap(&out[bit], &out[bit+1]);
    }
}

int main(void) {
    int height, width, goal;
    get_int3(&height, &width, &goal);
    // 1-indexed -> 0-indexed
    goal--;
    static int64_t dp[HEIGHT_MAX+2][WIDTH_MAX];
    dp[0][0] = 1;
    int h, w, pat;
    static char pat_valid[PATTERN_MAX];
    static int next_idx[WIDTH_MAX];
    for(pat = 0; pat < (1<<(width-1)); pat++) {
        int bit;
        int prev = 0;
        int flag = 1;
        for(bit = 0; bit < width-1; bit++) {
            int cur = !!(pat & (1<<bit));
            if(prev == cur && cur == 1) { flag = 0; break; }
            prev = cur;
        }
        pat_valid[pat] = flag;
#ifdef DEBUG
        int i;
        printf("%d -> %d\n", pat, pat_valid[pat]);
        get_next(pat, width, next_idx);
        for(i = 0; i < width; i++) printf(" %d", next_idx[i]);
        putchar('\n');
#endif
    }

    for(h = 1; h <= height; h++) {
        for(pat = 0; pat < (1<<(width-1)); pat++) {
            if(!pat_valid[pat]) continue;
            get_next(pat, width, next_idx);
            for(w = 0; w < width; w++) {
                int nidx = next_idx[w];
                dp[h][nidx] = (dp[h][nidx] + dp[h-1][w])%DIVISOR;
#ifdef DEBUG
                printf("[%d] dp[%d][%d] = %lld\n", w, h, nidx, dp[h][nidx]);
#endif
            }
        }
    }
    printf("%d\n", (int)dp[height][goal]);
    return 0;
}
