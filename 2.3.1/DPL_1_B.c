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

#define NUM_MAX 100
#define WEIGHT_MAX 10000

struct product {
    int value;
    int weight;
};
int main(void) {
    int num, ulimit;
    get_int2(&num, &ulimit);
    struct product prods[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        get_int2(&prods[i].value, &prods[i].weight);
    }

    static int dp[NUM_MAX+1][WEIGHT_MAX+1];
    int n, w;
    for(n = 1; n <= num; n++) {
        struct product p = prods[n-1];
        for(w = 1; w <= ulimit; w++) {
            // stay or take over
            dp[n][w] = max(dp[n-1][w], dp[n][w-1]);
            if(w>=p.weight) dp[n][w] = max(dp[n][w], dp[n-1][w-p.weight]+p.value);
        }
    }
    printf("%d\n", dp[num][ulimit]);
    return 0;
}
