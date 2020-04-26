#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 2005

#define LINE_MAX 80

char get_char(void) {
    char buf[3];
    scanf("%s", buf);
    return buf[0];
}

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int main(void) {
    int num = get_int();
    char str[BUF_SIZE];
    char rev_str[BUF_SIZE];
    int i;
    for(i = 0; i < num; i++) {
        str[i] = get_char();
        rev_str[num-1-i] = str[i];
    }

    int s = 0;
    int e = num-1;
    static char res[BUF_SIZE];
    int ridx = 0;
    while(1) {
        if(s>e) break;
        if(str[s] > str[e]) {
            res[ridx++] = str[e];
            e--;
        } else if (str[s] < str[e]) {
            res[ridx++] = str[s];
            s++;
        } else {
            int len = (e-s)/2;
            int cmp = strncmp(&str[s], &rev_str[num-1-e], len);
            // str1 >= str2
            if(cmp>=0) {
                res[ridx++] = str[e];
                e--;
            } else {
                res[ridx++] = str[s];
                s++;
            }
        }
    }
    for(i = 0; i < num; i++) {
        putchar(res[i]);
        if(!((i+1)%LINE_MAX)) putchar('\n');
    }
    return 0;
}
