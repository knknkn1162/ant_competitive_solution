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

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

#define NUM_MAX 4000
#define NUM2_MAX (NUM_MAX*NUM_MAX)

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int desc(const void *a1, const void *a2) {
    return *(int*)a2 - *(int*)a1;
}

#define SUM_MAX ((2<<28)+1)

int main(void) {
    int num = get_int();
    static int a[NUM_MAX];
    static int b[NUM_MAX];
    static int c[NUM_MAX];
    static int d[NUM_MAX];
    int i, j;
    for(i = 0; i < num; i++) {
        get_int4(&a[i], &b[i], &c[i], &d[i]);
    }

    static int sum2_1[NUM2_MAX+1];
    static int sum2_2[NUM2_MAX];
    int size = num*num;
    for(i = 0; i < num; i++) {
        for(j = 0; j < num; j++) {
            sum2_1[i*num+j] = a[i] + b[j];
            sum2_2[i*num+j] = c[i] + d[j];
        }
    }

    qsort(sum2_1, size, sizeof(int), asc);
    sum2_1[size] = -SUM_MAX; // guard
    qsort(sum2_2, size, sizeof(int), desc);

    j = 0;
    int64_t cnt = 0;
    int prev = sum2_1[0];
    int succ = 0;
    for(i = 0; i < size+1; i++) {
        int elem = sum2_1[i];
        if(elem == prev) {
            succ++; continue;
        }
        for(; j < size; j++) {
            int new = prev + sum2_2[j];
            if(new < 0) break;
            if(new == 0) cnt += succ;
        }
#ifdef DEBUG
        printf("sum1[%d] = %d, sum2[%d] = %d\n", i, sum2_1[i], j, sum2_2[j]);
#endif
        prev = elem;
        succ = 1;
    }
    printf("%lld\n", cnt);
    return 0;
}
