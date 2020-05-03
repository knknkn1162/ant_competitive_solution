#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 1000

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

#define NUM_MAX 100

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

int main(void) {
    int tlimit = get_int();
    int takos[NUM_MAX];
    int tako_num = get_int();
    fget_array(takos, tako_num);
    qsort(takos, tako_num, sizeof(int), asc);
    int customers[NUM_MAX];
    int cstm_num = get_int();
    fget_array(customers, cstm_num);
    qsort(customers, cstm_num, sizeof(int), asc);

    int i;
    int idx = 0;
    int flag = 1;
    for(i = 0; i < cstm_num; i++) {
        int ct = customers[i];
        for(; idx < tako_num; idx++) {
            if(takos[idx] >= ct-tlimit) break;
        }
        if(idx == tako_num) { flag = 0; break; }
        if(takos[idx] > ct) { flag = 0; break; }
#ifdef DEBUG
        printf("match: %d[%d] <-> %d[%d]\n", takos[idx], idx, ct, i);
#endif
        // next takoyaki
        idx++;
    }
    printf("%s\n", flag ? "yes" : "no");
    return 0;
}
