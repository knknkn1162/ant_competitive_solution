#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define TOWNS_MAX 8
#define VERTEX_MAX 200
#define INF 0x1f1f1f1f
#define BUF_SIZE (TOWNS_MAX*4+50)

int get_int3(int *a1, int *a2, int *a3) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d %d", a1, a2, a3);
#else
#error
#endif
  return 0;
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

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reversed(int *arr, int size) {
    int i;
    // no need to reverse operation
    if(size == 0 || size == 1) return;
    static int brr[TOWNS_MAX];
    for(i = 0; i < size; i++) {
        brr[size-i-1] = arr[i];
    }
    for(i = 0; i < size; i++) {
        arr[i] = brr[i];
    }
    return;
}

int next_permutation(int *arr, int size) {
    if(size == 0 || size == 1) return 0;
    int pos;
    int i;
    int cur = arr[size-1];
    for(pos = size-2; pos >= 0; pos--) {
        if(cur > arr[pos]) break;
        cur = arr[pos];
    }
    if(pos==-1) {
        // arr is the last permutation
        for(i = 0; i < size; i++) arr[i] = i;
        return 0;
    }
    for(i = size-1; i > pos; i--) {
        if(arr[pos] < arr[i]) break;
    }

    // swap pos <-> i
    swap(&arr[pos], &arr[i]);
    reversed(&arr[pos+1], size-1-pos);
    return 1;
}

int main(void) {
    int vs, es, ts;
    get_int3(&vs, &es, &ts);
    static int arr[TOWNS_MAX];
    int i, j, k;
    fget_array(arr, ts);
    // 1-indexed -> 0-indexed
    for(i = 0; i < vs; i++) arr[i]--;

    static int graph[VERTEX_MAX][VERTEX_MAX];
    memset(graph, 0x1f, sizeof(int)*VERTEX_MAX*VERTEX_MAX);
    for(i = 0; i < vs; i++) graph[i][i] = 0;

    for(i = 0; i < es; i++) {
        int v1, v2, dist;
        get_int3(&v1, &v2, &dist);
        // 1-indexed -> 0-indexed
        v1--; v2--;
        graph[v1][v2] = graph[v2][v1] = dist;
    }

    // warshall floyd
    for(k = 0; k < vs; k++) {
        for(i = 0; i < vs; i++) {
            for(j = 0; j < vs; j++) {
                int new = graph[i][k] + graph[k][j];
                if(graph[i][j] > new) {
                    graph[i][j] = new;
                }
            }
        }
    }

    // permutation
    static int perm[TOWNS_MAX];
    for(i = 0; i < ts; i++) perm[i] = i;

    int ans = INF; // minimum
    do {
#ifdef DEBUG
        printf("perm: ");
        for(i = 0; i < ts; i++) {
            printf("%d ", arr[perm[i]]);
        }
        putchar('\n');
#endif
        int res = 0;
        int cur = arr[perm[0]];
        for(i = 1; i < ts; i++) {
            int next = arr[perm[i]];
            res += graph[cur][next];
            cur = next;
        }
#ifdef DEBUG
        printf("res: %d\n", res);
#endif
        ans = min(ans, res);
    } while(next_permutation(perm, ts));

    printf("%d\n", ans);
    return 0;
}
