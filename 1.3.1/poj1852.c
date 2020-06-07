#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 1000000
#define LENGTH_MAX 1000000

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
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

struct pair {
    int min;
    int max;
};

// ensure that a <= b
struct pair create_pair(int a, int b) {
    if(a>b) { return (struct pair){b, a}; }
    return (struct pair){a, b};
}

int main(void) {
    int inputs = get_int();
    //static struct pair ans[SET_MAX];
    static int arr[NUM_MAX];
    //int aidx = 0;
    int i, j;
    for(i = 0; i < inputs; i++) {
        int len, num;
        get_int2(&len, &num);
        fget_array(arr, num);
        struct pair res = {0, 0};
        for(j = 0; j < num; j++) {
            struct pair p = create_pair(arr[j], len-arr[j]);
            res.min = max(res.min, p.min);
            res.max = max(res.max, p.max);
        }
        printf("%d %d\n", res.min, res.max);
        //ans[aidx++] = res;
    }

    return 0;
}
