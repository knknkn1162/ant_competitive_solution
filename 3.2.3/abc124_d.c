#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

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
#define BUF_SIZE (NUM_MAX+50)

int main(void) {
    int num, changes;
    get_int2(&num, &changes);

    char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int i;
    for(i = 0; i < num; i++) str[i] = (str[i] == '1');
    str[num] = !(str[num-1]);

    // #1 #0 #1 #0...
    static int arr[NUM_MAX*4]; // 2*changes + 1 + aidx < NUM_MAX*4
    int aidx = 0;
    char prev = 1;
    int cnt = 0;
    for(i = 0; i <= num; i++) {
        if(str[i] == prev) { cnt++; continue; }
        arr[aidx++] = cnt;
        prev = str[i];
        cnt = 1;
    }
#ifdef DEBUG
    for(i = 0; i < aidx; i++) {
        printf(" %d", arr[i]);
    }
    putchar('\n');
#endif

    static int cum[NUM_MAX*4];
    for(i = 1; i < NUM_MAX*4; i++) {
        cum[i] = cum[i-1] + arr[i-1];
    }

    int ans = 0;
    int ranges = 2*changes+1;
    for(i = 0; i < aidx; i+=2) {
        ans = max(ans, cum[i+ranges] - cum[i]);
        if(i+ranges > aidx) break;
    }
    printf("%d\n", ans);
    return 0;
}
