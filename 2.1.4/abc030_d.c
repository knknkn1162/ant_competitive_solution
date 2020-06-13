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

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
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

#define NUM_MAX 100000
#define BUF_MAX 100050
#define TRANS_MAX (NUM_MAX*3)

int main(void) {
    int num = get_int();
    int init = get_int();
    static char s[BUF_MAX];
    get_str(s, BUF_MAX);
    int len = strlen(s);

    static int arr[NUM_MAX+1];
    fget_array(&arr[1], num);
    static int trans[TRANS_MAX];
    int i;
    trans[0] = init;
    for(i = 1; i < TRANS_MAX; i++) {
        trans[i] = arr[trans[i-1]];
    }

    static int map[NUM_MAX+1];
    memset(map, 0xff, sizeof(int)*(NUM_MAX+1));
    int start, end;
    for(i = 0; i < TRANS_MAX; i++) {
        int cur = trans[i];
        if(map[cur] != -1) {
            start = map[cur];
            end = i;
            break;
        }
        map[cur] = i;
    }
#ifdef DEBUG
    printf("%d, %d\n", start, end);
    for(i = 0; i < 10; i++) {
        printf(" %d", trans[i]);
    }
    putchar('\n');
#endif

    int divisor = end - start;
    int ans = 0;
    // k is small
    if(len <= 7) {
        int k = strtol(s, NULL, 0);
        if(k < TRANS_MAX) {
            ans = trans[k];
        }
    } else {
        int mod = 0;
        for(i = 0; i < len; i++) {
            int d = s[i] - '0';
            mod = (mod * 10+d)%divisor;
        }
        // this is necessary!!
        mod -= start;
        while(mod<0) {
            mod += divisor;
        }
        mod %= divisor;
        ans = trans[start+mod];
    }
    printf("%d\n", ans);
    return 0;
}
