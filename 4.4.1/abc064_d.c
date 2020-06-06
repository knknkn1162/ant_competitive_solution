#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

static char stack[200];
static int sidx = 0;
#define STR_MAX 100

void push(char ch) {
    stack[sidx++] = ch;
}

int pop(void) {
    return stack[--sidx];
}

int is_empty(void) { return !sidx; }

int main(void) {
    int num = get_int();
    char str[STR_MAX];
    int pre_cnt = 0;
    get_str(str, num);
    int i;
    for(i = 0; i < num; i++) {
        switch(str[i]) {
            case '(':
                push(str[i]);
                break;
            case ')':
                if(is_empty()) {
                    pre_cnt++;
                } else {
                    pop();
                }
                break;
            default:
                break;
        }
    }
    for(i = 0; i < pre_cnt; i++) {
        putchar('(');
    }
    for(i = 0; i < num; i++) {
        putchar(str[i]);
    }
    for(i = 0; i < sidx; i++) {
        putchar(')');
    }
    putchar('\n');
    return 0;
}
