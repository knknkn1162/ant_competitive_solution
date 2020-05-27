#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define STR_MAX 20000
#define BUF_MAX (STR_MAX+50)

enum type {
    TYPE_DOWN = '\\',
    TYPE_UP = '/',
    TYPE_FLAT = '_'
};

struct rect {
    int depth;
    int left;
};

struct stack {
    void *s;
    int idx;
};

static struct rect stack[BUF_MAX];
static int sidx;

struct rect peek(void) { return stack[sidx-1]; }
int is_empty(void) { return !sidx; }

void push(struct rect r) { stack[sidx++] = r; }
struct rect pop(void) { return stack[--sidx]; }


struct pair {
    int depth;
    int area;
};

static struct pair pstack[BUF_MAX];
static int pidx;
struct pair pair_pop(void) {return pstack[--pidx];}
void pair_push(struct pair p) { pstack[pidx++] = p; }
struct pair pair_peek(void) { return pstack[pidx-1]; }
int is_pair_empty(void) { return !pidx; }


int main(void) {
    static char str[BUF_MAX];
    get_str(str, BUF_MAX);
    int len = strlen(str);

    int right;
    int depth = 0;
    int sum = 0;
    for(right = 0; right < len; right++) {
        switch(str[right]) {
            case TYPE_DOWN:
                {
                    struct rect r = {depth, right};
                    push(r);
                    depth++;
                }
                break;
            case TYPE_UP:
                {
                    depth--;
                    if(is_empty()) {
                        pair_push((struct pair){depth, 0});
                        break;
                    }
                    struct rect r = pop();
                    int newarea = 0;
                    while(!is_pair_empty()) {
                        struct pair p = pair_peek();
                        // if p is higher, break;
                        if(p.depth <= depth) break;
                        newarea += p.area;
                        pair_pop();
                    }
                    if(r.depth == depth) {
                        sum += (right - r.left);
                        newarea += right-r.left;
                    }
                    pair_push((struct pair){depth, newarea});
                }
                break;
            case TYPE_FLAT:
                break;
            default:
                break;
        }
    }
    printf("%d\n", sum);
    int i;

    int cnt = 0;
    for(i = 0; i < pidx; i++) cnt += !!(pstack[i].area);
    printf("%d", cnt);
    for(i = 0; i < pidx; i++) {
        if(pstack[i].area) printf(" %d", pstack[i].area);
    }
    putchar('\n');
    return 0;
}
