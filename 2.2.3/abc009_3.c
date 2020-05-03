#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 110

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int asc(const void *a1, const void *a2) {
    return *(char*)a1 - *(char*)a2;
}

int main(void) {
    int num, ulimits;
    static char str[BUF_SIZE];
    get_int2(&num, &ulimits);
    get_str(str, BUF_SIZE);
    int len = strlen(str) - 1;
    int i;
    if(ulimits==0 || ulimits==1) {
        goto finish;
    }
    // calc fastest word
    static char first[BUF_SIZE];
    int fidx = 0;
    static int map[26];
    for(i = 0; i < len; i++) {
        map[str[i]-'a']++;
    }
    for(i = 0; i < 26; i++) {
        if(map[i]--) first[fidx++] = (i+'a');
    }
#ifdef DEBUG
    printf("first: %s\n", first);
#endif

    // assume that 2<= ulimits
    static char changed[BUF_SIZE];
    static char stack[BUF_SIZE];
    int changed_cnt = 0;
    int pos;
    for(i = 0; i < len; i++) {
        if(first[i] == str[i]) continue;
        if(!changed[i] && changed_cnt+1 == ulimits) {
            int argf = i;
            for(pos = i+1; pos < len; pos++) {
                if(!changed[pos] && str[argf] > str[pos]) {
                    argf = pos;
                }
                if(changed[pos] && str[i] > str[pos]) break;
            }
            if(pos == len) {
                changed[argf] = 1;
                stack[changed_cnt++] = str[argf];
                break;
            }
        } else {
            // search first[i] from tail
            for(pos = len-1; pos >= i+1; pos--) {
                if(first[i] == str[pos]) break;
            }
        }

#ifdef DEBUG
        printf("%d <-> %d\n", i, pos);
#endif
        if(!changed[i]) stack[changed_cnt++] = str[i];
        if(!changed[pos]) stack[changed_cnt++] = str[pos];
        changed[i] = changed[pos] = 1;
        swap(&str[i], &str[pos]);
#ifdef DEBUG
        printf("[change %d charas] %s", changed_cnt, str);
#endif
        if(changed_cnt == ulimits) break;
    }
    qsort(stack, changed_cnt, sizeof(char), asc);
    int sidx = 0;
    // sort changed character
    for(i = 0; i < len; i++) {
        if(changed[i]) {
            str[i] = stack[sidx++];
        }
    }
finish:
    printf("%.*s\n", len, str);
    return 0;
}
