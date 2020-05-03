#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 800
#define BUF_SIZE (NUM_MAX*7+50)
#define SET_MAX 1000

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

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
int fget_array(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

int abs_desc(const void *a1, const void *a2) {
    return abs(*(int*)a2) - abs(*(int*)a1);
}

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

// ./a.out < A-small-practice.in > out.txt
int main(void) {
    int sets = get_int();
    static int64_t ans[SET_MAX];
    int aidx = 0;
    int s, i;
    for(s = 0; s < sets; s++) {
        int num = get_int();
        static int arr[NUM_MAX];
        static int brr[NUM_MAX];
        fget_array(arr, num);
        qsort(arr, num, sizeof(int), abs_desc);
        fget_array(brr, num);
        qsort(brr, num, sizeof(int), asc);
        int fit = 0;
        int lit = num-1;
        int64_t res = 0;
        for(i = 0; i < num; i++) {
            int n = arr[i];
            if(n < 0) {
                res += (int64_t)n * brr[lit--];
            } else {
                res += (int64_t)n * brr[fit++];
            }
        }
        ans[aidx++] = res;
    }
    for(i = 0; i < aidx; i++) {
        printf("Case #%d: %lld\n", i+1, ans[i]);
    }
    return 0;
}
