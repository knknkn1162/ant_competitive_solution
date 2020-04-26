#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define VERTEXES_MAX 8
#define PERM_SIZE VERTEXES_MAX
#define BUF_SIZE 100

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

#ifndef PERM_SIZE
#define PERM_SIZE 30
#endif
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// assume that size is smaller..
void reversed(int *a, int size) {
    static int b[PERM_SIZE];
    memcpy(b, a, sizeof(int)*size);
    int i;
    for(i = 0; i < size; i++) {
        a[i] = b[size-1-i];
    }
}

// in-place(C++ like function)
// see also https://cpprefjp.github.io/reference/algorithm/next_permutation.html
int next_permutation(int *arr, int size) {
    int i, k;
    if(!size || size==1) return 0;
    // step1. 
    for(k = size-2; k >= 0; k--) {
        if(arr[k+1] > arr[k]) break;
    }
    if(k < 0) {
        // reversed
        reversed(arr, size);
        return 0;
    }
    for(i = size-1; i >= 0; i--) {
        if(arr[i] < arr[k]) continue;
        break;
    }
    swap(&arr[i], &arr[k]);
    reversed(&arr[k+1], size-1-k);
    return 1;
}

int main(void) {
    int vs, es;
    static char graph[VERTEXES_MAX][VERTEXES_MAX];
    get_int2(&vs, &es);
    int i;
    for(i = 0; i < es; i++) {
        int v1, v2;
        get_int2(&v1, &v2);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        // undirected
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    int arr[VERTEXES_MAX];
    for(i = 0; i < vs; i++) arr[i] = i;

    int cnt = 0;
    do {
        // starting point must be 0
        if(arr[0] != 0) break;
#ifdef DEBUG
        for(i = 0; i < vs; i++) printf("%d ", arr[i]);
        putchar('\n');
#endif
        int flag = 1;
        for(i = 1; i < vs; i++) {
            if(graph[arr[i-1]][arr[i]]) continue;
            flag = 0;
            break;
        }
        if(flag) cnt++;
    } while(next_permutation(arr, vs));

    printf("%d\n", cnt);
    return 0;
}
