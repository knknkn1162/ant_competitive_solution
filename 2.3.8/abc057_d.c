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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

// sort
int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}

#define NUM_MAX 50

static int64_t combi[NUM_MAX+1][NUM_MAX+1];
void init_combi(int num){
    int i, j;
    for(i=0; i<=num; i++) {
        for(j=0; j<=i; j++) {
            if(j == 0 || j == i) combi[i][j] = 1;
            else {
                combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]);
            }
        }
    }
}

int main(void) {
    int num = get_int();
    int ulimit, llimit;
    get_int2(&llimit, &ulimit);
    static int64_t arr[NUM_MAX];
    fget_array(arr, num);
    init_combi(NUM_MAX);
    qsort(arr, num, sizeof(int64_t), desc);
    
    int i;
    double sum = 0;
    for(i = 0; i < llimit; i++) {
        int64_t cur = arr[i];
        sum += cur;
    }
    int64_t prev = arr[llimit-1];
    double ave = sum / llimit;

    int n = 0;
    int k = 0;
    for(i = 0; i < num; i++) {
        if(prev == arr[i]) {
            n++;
            if(i < llimit) k++;
        }
    }

    int64_t ans = 0;
    if(prev == arr[0]) {
        // [llimit-1, i) -> [llimit, i+1)
        for(i = llimit; i <= min(ulimit, n); i++) {
            ans += combi[n][i];
        }
    } else {
        ans = combi[n][k];
    }

    printf("%.8lf\n", ave);
    printf("%lld\n", ans);
    return 0;
}
