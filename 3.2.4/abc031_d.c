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
#define WORD_STR_MAX 30
#define NUM_MAX 50
#define DIGIT_STR_MAX 15
struct goro {
    char digits[DIGIT_STR_MAX];
    int dlen;
    char word[WORD_STR_MAX];
    int wlen;
};

int get_str(struct goro *goro)
{
    char format[100];
    snprintf(format, sizeof(format), "%%%ds", DIGIT_STR_MAX);
    scanf(format, goro->digits);
    goro->dlen = strlen(goro->digits);
    snprintf(format, sizeof(format), "%%%ds", WORD_STR_MAX);
    scanf(format, goro->word);
    goro->wlen = strlen(goro->word);
    return 0;
}

#define S_MAX 4
#define DIGITS 10
static char ans[DIGITS+1][S_MAX];
int judge(struct goro *gs, int size, int *map, int ds) {
    int i, j;
    memset(ans, 0x00, (DIGITS+1)*S_MAX);
    for(i = 0; i < size; i++) {
        struct goro g = gs[i];
        int pos = 0;
        for(j = 0; j < g.dlen; j++) {
            int d = g.digits[j] - '0';
            char *cur = &g.word[pos];
            if(ans[d][0]) { // if exists
                if(memcmp(ans[d], cur, map[d])!=0) return 0;
            } else {
                // create
                memcpy(ans[d], cur, map[d]);
            }
            pos += map[d];
        }
        if(pos != g.wlen) return 0;
    }
    return 1;
}

int main(void) {
    int ds, num;
    get_int2(&ds, &num);

    static struct goro goros[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        get_str(&goros[i]);
    }

    int pat;
    int bitmax = ds*2;
    for(pat = 1; pat < (1<<bitmax); pat++) {
        int map[11] = {0};
        int flag = 1;
        for(i = 0; i < ds; i++) {
            int cnt = (pat >> (i*2)) & 3;
            if(!cnt) flag = 0;
            map[i+1] = cnt;
        }
        if(!flag) continue;
        // assume that map[i] >= 1 for all i
        if(judge(goros, num, map, ds)) break;
    }

    for(i = 1; i <= ds; i++) {
        printf("%s\n", ans[i]);
    }
    return 0;
}
