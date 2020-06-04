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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

struct programs {
    int start;
    int end;
    int channel;
};

#define CHANNEL_MAX 30
#define TIME_MAX 200000

int main(void) {
    int num, cs;
    get_int2(&num, &cs);
    int i;

    static int map[CHANNEL_MAX][TIME_MAX+4];
    for(i = 0; i < num; i++) {
        int start, end, channel;
        get_int3(&start, &end, &channel);
        // 1-indexed -> 0-indexed
        channel--;
        // for avoiding 0.5
        start*=2;
        end*=2;
        map[channel][start]++;
        map[channel][end]--;
    }

    int c;
    // imos restore
    for(c = 0; c < cs; c++) {
        for(i = 1; i <= TIME_MAX+3; i++) {
            map[c][i] += map[c][i-1];
        }
    }
#ifdef DEBUG
    for(c = 0; c < cs; c++) {
        for(i = 0; i <= 100; i+=2) {
            printf(" %d", map[c][i]);
        }
        putchar('\n');
    }
#endif


    static int map2[TIME_MAX+4];
    for(c = 0; c < cs; c++) {
        int prev = 0;
        for(i = 0; i <= TIME_MAX+3; i++) {
            int cur = map[c][i];
            if(prev == 0 && cur == 1) {
                map2[i-1]++; // S-0.5
            } else if (prev == 1 && cur == 0) {
                map2[i]--; // T
            }
            prev = cur;
        }
    }

    int ans = map2[0];
    // imos restore
    for(i = 1; i <= TIME_MAX+3; i++) {
        map2[i] += map2[i-1];
        ans = max(ans, map2[i]);
    }
    printf("%d\n", ans);

    return 0;
}
