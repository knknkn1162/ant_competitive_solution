#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 4000
#define BUF_SIZE (NUM_MAX*12+50)

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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(uint64_t *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtoll(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

#define INF (uint64_t)(0x0101010101010101)

int main(void) {
    int num = get_int();
    static uint64_t arr[NUM_MAX];
    fget_array(arr, num);
    static uint64_t dp[NUM_MAX+1][NUM_MAX+1];

    static uint64_t cum[NUM_MAX+1];
    int i;
    for(i = 1; i <= num; i++) {
        cum[i] = cum[i-1] + arr[i-1];
    }

    int size, start, start2;
    for(size = 2; size <= num; size++) {
        // calc for [0, size)
        uint64_t res = INF;
        int argmin = 0;
        start = 0;
        for(start2 = 1; start2 <= size-1; start2++) {
            uint64_t new = dp[start2-start][start] + dp[size-start2][start2];
            if(res > new) {
                argmin = start2;
                res = new;
            }
        }
        dp[size][0] = res + cum[size] - cum[0];
#ifdef DEBUG
        printf("argmin: %d dp[size][0] = %llu \n", argmin, dp[size][0]);
#endif
        for(start = 1; start <= num-size; start++) {
            int end = start + size;
            // [start, start+size)
            uint64_t cost = cum[end] - cum[start];
            int newargmin;
            uint64_t res = INF;
            // we can verify O(1) by Monge
            for(start2 = argmin; start2 <= argmin + 1; start2++) {
                // must be start < start2 < end
                if(start2 <= start || start2 >= end) continue;
                uint64_t new = dp[start2-start][start] + dp[end-start2][start2];
#ifdef DEBUG
                printf("%llu = dp[%d][%d] + dp[%d][%d]\n", new, start2-start, start, end-start2, start2);
#endif
                if(res > new) {
                    newargmin = start2;
                    res = new;
                }
            }
            dp[size][start] = res + cost;
            argmin = newargmin;
#ifdef DEBUG
            printf("argmin: %d", argmin);
            printf("dp[%d][%d] = %llu\n", size, start, dp[size][start]);
#endif
        }
    }
    printf("%llu\n", dp[num][0]);
    return 0;
}
