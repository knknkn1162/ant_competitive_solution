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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100000

struct rect {
    int height;
    int left;
};

static struct rect stack[NUM_MAX+10];
static int sidx = 0;

void push(struct rect r) { stack[sidx++] = r; }
struct rect pop(void) { return stack[--sidx]; }
struct rect peek(void) { return stack[sidx-1]; }

int is_empty(void) { return !sidx; }

int main(void) {
    int num = get_int();
    static int arr[NUM_MAX+1];
    fget_array(arr, num);
    arr[num] = 0;

    int right;
    int64_t ans = 0;
    for(right = 0; right < num+1; right++) {
        struct rect r = {arr[right], right};
        while(!is_empty()) {
            struct rect top = peek();
            if(top.height < r.height) break;
            ans = max(ans, (int64_t)top.height*(right-top.left));
            r.left = top.left;
            pop();
        }
        push(r);
    }

    printf("%lld\n", ans);
    return 0;
}
