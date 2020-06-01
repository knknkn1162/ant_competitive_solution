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

#define STR_MAX 5000
#define BUF_SIZE (STR_MAX+50)
#define NUM_MAX (STR_MAX*10)
#define K_MAX 5

int asc(const void *a1, const void *a2) {
    char *s1 = (char*)a1;
    char *s2 = (char*)a2;
    return memcmp(s1, s2, K_MAX+1);
}

int main(void) {
    static char str[BUF_SIZE];
    get_str(str, BUF_SIZE);
    int len = strlen(str);
    int k = get_int();
    static char cands[NUM_MAX][K_MAX+1];
    int cidx = 0;

    int size, start;
    for(size = 1; size <= k; size++) {
        for(start = 0; start < len-size+1; start++) {
            memcpy(cands[cidx++], &str[start], size);
        }
    }
    int i;

    qsort(cands, cidx, sizeof(char)*(K_MAX+1), asc);
    static char s[K_MAX+1];
    for(i = 0; i < cidx; i++) {
        if(!memcmp(s, cands[i], K_MAX+1)) continue;
        // update
        memcpy(s, cands[i], K_MAX+1);
        k--;
        if(!k) break;
    }

    printf("%s\n", s);
    return 0;
}
