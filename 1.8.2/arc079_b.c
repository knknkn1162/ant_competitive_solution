#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int64_t get_int(void) {
  int64_t num;
  scanf("%lld", &num);
  return num;
}

#define NUM_MAX 50
int main(void) {
    int64_t k = get_int();
    int64_t quo = k/NUM_MAX;
    int64_t rem = k%NUM_MAX;

    int64_t arr[NUM_MAX];
    int i;
    for(i = 0; i < rem; i++) {
        arr[i] = quo + NUM_MAX;
    }
    for(i = rem; i < NUM_MAX; i++) {
        arr[i] = quo + (NUM_MAX-rem-1);
    }

    printf("%d\n", NUM_MAX);
    for(i = 0; i < NUM_MAX; i++) {
        printf("%lld%c", arr[i], i == (NUM_MAX-1) ? '\n' : ' ');
    }
    return 0;
}
