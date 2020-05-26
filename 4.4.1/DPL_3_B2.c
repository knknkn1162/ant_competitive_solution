#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define min3(a,b,c) min(min(a,b),c)

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(char *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    return 0;
}

#define NUM_MAX 1400

struct rect {
    int height;
    int pos;
};
static struct rect stack[NUM_MAX+1];
static int idx = 0;

void init_stack(void) { idx=0; }
int is_empty(void) {
    return idx==0;
}

void push(struct rect r) {
    stack[idx++] = r;
}

struct rect pop(void) {
    return stack[--idx];
}

struct rect peek(void) {
    return stack[idx-1];
}

int main(void) {
    int height, width;
    get_int2(&height, &width);
    static char mat[NUM_MAX+1][NUM_MAX+1];
    int i, j;
    for(i = 1; i <= height; i++) {
        fget_array(&mat[i][1], width);
        // 0: dirty, 1: clean(usable)
        for(j = 1; j <= width; j++) mat[i][j] = 1-mat[i][j];
    }

    static int hist[NUM_MAX+2][NUM_MAX+2];
    for(i = 1; i <= height; i++) {
        for(j = 1; j <= width; j++) {
            if(!mat[i][j]) {
                hist[i][j] = 0;
            } else {
                hist[i][j] = hist[i-1][j] + 1;
            }
        }
        hist[i][width+1] = 0;
    }
#ifdef DEBUG
    for(i = 1; i <= height; i++) {
        for(j = 1; j <= width; j++) {
            printf(" %d", hist[i][j]);
        }
        putchar('\n');
    }
#endif

    int ans = 0;
    for(i = 1; i <= height; i++) {
        init_stack();
        for(j = 1; j <= width+1; j++) {
            struct rect cur = {hist[i][j], j};
            while(!is_empty()) {
                struct rect pr = peek();
                if(pr.height < cur.height) break;
#ifdef DEBUG
                printf("(%d, %d) height: %d, width: %d\n", i, j, pr.height, j-pr.pos);
#endif
                ans = max(ans, (j-pr.pos)*pr.height);
                cur.pos = pr.pos; // update smaller
                pop();
            }
            push(cur);
        }
    }
    printf("%d\n", ans);

    return 0;
}
