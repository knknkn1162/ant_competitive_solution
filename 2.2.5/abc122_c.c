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

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define NUM_MAX 100000
#define QUERY_MAX 100000


int main(void) {
    int num, queries;
    get_int2(&num, &queries);
    static char str[NUM_MAX];
    get_str(str, num);

    int i;
    char prev = str[0];
    static char match[NUM_MAX];
    for(i = 1; i < num; i++) {
        if(prev == 'A' && str[i] == 'C') match[i] = 1;
        prev = str[i];
    }

    static int cum[NUM_MAX+1];
    for(i = 1; i <= num; i++) {
        cum[i] = cum[i-1] + match[i-1];
    }

    int q;
    static int ans[QUERY_MAX];
    int aidx = 0;
    for(q = 0; q < queries; q++) {
        int start, end;
        get_int2(&start, &end);
        start--; end--;
        // [start, end)
        end++;
        int res = cum[end] - cum[start];
        if(str[start] == 'C' && match[start]) res-= 1;
        ans[aidx++] = res;
    }

    // presentation
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
