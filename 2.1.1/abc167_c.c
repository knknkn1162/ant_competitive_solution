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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define BOOK_MAX 12
#define ALGO_MAX 12
#define INF (1e+7)

void read(int *profits, int *out, int size) {
    int i;
    for(i = 0; i < size; i++) {
        out[i] += profits[i];
    }
}

int main(void) {
    int books, algos, llimit;
    int prices[BOOK_MAX];
    int profits[BOOK_MAX][ALGO_MAX];
    get_int3(&books, &algos, &llimit);
    int i;
    for(i = 0; i < books; i++) {
        prices[i] = get_int();
        fget_array(profits[i], algos);
    }

    int pat, bit;
    int ans = INF;
    for(pat = 1; pat < (1<<books); pat++) {
        int cost = 0;
        int skills[ALGO_MAX] = {0};
        // judge
        int flag = 1;
        for(bit = 0; bit < books; bit++) {
            if(!(pat & (1<<bit))) continue;
            read(profits[bit], skills, algos);
            cost += prices[bit];
            if(ans < cost) { flag = 0; break; }
        }
#ifdef DEBUG
        printf("%d -> %d\n", pat, cost);
#endif
        if(!flag) continue; // skip
        for(i = 0; i < algos; i++) {
            if(skills[i] < llimit) flag = 0;
        }
        if(flag) ans = min(ans, cost);
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
