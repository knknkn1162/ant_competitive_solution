#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

#define STR_MAX 500000
// 524288
#define NUM_MAX (1<<19)
#define BUF_SIZE (STR_MAX+100)
#define QUERY_MAX 20000
#define LOWER_NUM 26

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_intch(int *a, char *ch) {
    return scanf("%d %c", a, ch);
}

int get_int2(int *a, int *b) {
    return scanf("%d %d", a, b);
}

// include '\n'
int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

enum type {
    COMMAND_UPDATE = 1,
    COMMAND_GET
};

// assume that 'a' - 'z'
char get_pos(char ch) {
    return ch - 'a';
}

void update(int *seg, int num, int idx, int bit) {
    int node = num + idx;
    seg[node] = bit;
    while((node = node/2)) {
        seg[node] = seg[node*2] | seg[node*2+1];
    }
#ifdef DEBUG
    int i;
    for(i = num; i < 2*num; i++) {
        printf(" %d", seg[i]);
    }
    putchar('\n');
#endif
    return;
}

struct range {
    int start;
    int end;
};

int is_overlap(struct range r1, struct range r2) {
    return r1.end >= r2.start && r2.end >= r1.start;
}

int is_contain(struct range this, struct range in) {
    return in.start <= this.start && in.end >= this.end;
}

int get_pat(int *seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) {
        return seg[node];
    }
    // otherwise
    struct range left = {nr.start, (nr.start+nr.end)/2};
    struct range right = {left.end+1, nr.end};
    return get_pat(seg, r, node*2, left) | get_pat(seg, r, node*2+1, right);
}

int main(void) {
    int _num = get_int();
    int num = 1;
    while(_num >= num) num *= 2;
    static char str[BUF_SIZE];
    get_str(str, _num);

    int queries = get_int();
    static int seg[NUM_MAX*2];
    static int ans[QUERY_MAX];
    int aidx = 0;
    int i;
    // initialization
    for(i = 0; i < _num; i++) {
        int idx = get_pos(str[i]);
        update(seg, num, i, (1<<idx));
    }

    struct range whole = {0, num-1};
    for(i = 0; i < queries; i++) {
        int type = get_int();
        switch(type) {
            case COMMAND_UPDATE:
                {
                    int idx; char newch;
                    get_intch(&idx, &newch);
                    idx--;
                    int pos = get_pos(newch);
                    update(seg, num, idx, (1<<pos));
                }
                break;
            case COMMAND_GET:
                {
                    int start, end;
                    get_int2(&start, &end);
                    start--; end--;
                    struct range r = {start, end};
                    int pat = get_pat(seg, r, 1, whole);
                    ans[aidx++] = __builtin_popcount(pat);
                }
                break;
            default:
                break;
        }
    }
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
}
