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

#define M_MAX 17
#define NUM_MAX (2<<M_MAX)

int main(void) {
    int m, k;
    get_int2(&m, &k);
    if(m == 1) {
        if(k == 0) {
            printf("0 0 1 1\n");
            return 0;
        }
        goto impossible;
    }
    int ulimit = (1<<m);
    if(k >= ulimit) goto impossible;

    static int ans[NUM_MAX];
    int idx = 0;
    ans[idx++] = k;
    int i;
    for(i = 0; i < ulimit; i++) {
        if(i == k) continue;
        ans[idx++] = i;
    }
    ans[idx++] = k;
    for(i = ulimit-1; i >= 0; i--) {
        if(i == k) continue;
        ans[idx++] = i;
    }

    for(i = 0; i < idx; i++) {
        printf("%d%c", ans[i], (i == idx-1) ? '\n' : ' ');
    } 
    return 0;


impossible:
    printf("-1\n");
    return 0;
}
