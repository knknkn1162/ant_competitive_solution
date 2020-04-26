/*
5
1 2 4 6 8
3 5 7 9 10
=> 3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 100000
#define BUF_SIZE (NUM_MAX*11+100)

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

struct range {
    int start;
    int end;
};

int asc_by_start(const void *a1, const void *a2) {
    struct range *ra1 = (struct range*)a1;
    struct range *ra2 = (struct range*)a2;
    return ra1->start - ra2->start;
}

int asc_by_end(const void *a1, const void *a2) {
    struct range *ra1 = (struct range*)a1;
    struct range *ra2 = (struct range*)a2;
    return ra1->end - ra2->end;
}

int main(void) {
    int num = get_int();
    int start[NUM_MAX];
    int end[NUM_MAX];
    struct range ranges[NUM_MAX];
    struct range ranges_by_end[NUM_MAX];
    int i;
    fget_array(start, num);
    fget_array(end, num);
    for(i = 0; i < num; i++) {
        ranges[i] = (struct range){start[i], end[i]};
    }
    memcpy(ranges_by_end, ranges, sizeof(struct range)*num);
    qsort(ranges_by_end, num, sizeof(struct range), asc_by_end);

    struct range prev = ranges_by_end[0];
#ifdef DEBUG
        printf("[%d %d]\n", prev.start, prev.end);
#endif
    int cnt = 1;
    for(i = 1; i < num; i++) {
        struct range cur = ranges_by_end[i];
        // must be [prev.end, start]
        if(prev.end+1 > cur.start) continue;
#ifdef DEBUG
        printf("[%d %d]\n", cur.start, cur.end);
#endif
        prev = cur;
        cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
