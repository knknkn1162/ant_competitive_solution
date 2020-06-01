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

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define NUM_MAX 150

int main(void) {
    int num = get_int();
    char str[NUM_MAX];
    get_str(str, num);

    int i, j;
    static int map[NUM_MAX];
    int ans = 0;
    for(i = 0; i < num-1; i++) {
        map[str[i]-'a']++;
        // [0, i] and [i+1, i]
        int res = {0};
        for(j = i+1; j < num; j++) {
            int idx = str[j] - 'a';
            if(map[idx]) res |= (1<<idx);
        }
        ans = max(ans, __builtin_popcount(res));
    }
    printf("%d\n", ans);
}
