#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 50
#define WEIGHT_MAX 100000
#define BUF_SIZE 20

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX];
    int i, j;
    for(i = 0; i < num; i++) {
        arr[i] = get_int();
    }
    static int stack[NUM_MAX][NUM_MAX];
    static int sidx[NUM_MAX] = {0};
    int cnt = 0;
    stack[cnt][sidx[cnt]++] = arr[0];
    for(i = 1; i < num; i++) {
        int cur = arr[i];
        int diff = WEIGHT_MAX+1;
        int pos = -1;
        // lower bound >= arr[i]
        for(j = 0; j <= cnt; j++) {
            int ndiff = stack[j][sidx[j]-1] - cur;
            if(ndiff >= 0 && ndiff < diff) {
                diff = ndiff;
                pos = j;
            }
        }

#ifdef DEBUG
        printf("[%d]=%d -> %d\n", i, arr[i], pos);
#endif
        if(pos==-1) {
            cnt++;
            stack[cnt][sidx[cnt]++] = cur;
        } else {
            stack[pos][sidx[pos]++] = cur;
        }
    }
    printf("%d\n", cnt+1);
    return 0;
}
