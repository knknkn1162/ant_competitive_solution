#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

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

#define NUM_MAX 200000
#define QUERY_MAX 200000

int main(void) {
    int num = get_int();
    static int os[NUM_MAX+1];

    int i;
    int queries = get_int();
    for(i = 0; i < queries; i++) {
        int start, end;
        get_int2(&start, &end);
        // 1-indexed -> 0-indexed
        start--; end--;
        // [start, end)
        end++;
        os[start]++;
        os[end]--;
    }

    for(i = 1; i < num; i++) {
        os[i] += os[i-1];
    }
    
    for(i = 0; i < num; i++) {
        putchar('0' + os[i]%2);
    }
    putchar('\n');
    return 0;
}
