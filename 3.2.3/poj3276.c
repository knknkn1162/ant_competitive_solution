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
int fget_array(char *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        char ch;
        scanf("\n%c", &ch);
        arr[i] = (ch == 'F');
    }
    return 0;
}

#define NUM_MAX 5000

int main(void) {
    int num = get_int();
    static char arr[NUM_MAX];
    fget_array(arr, num);
    int k, i;
#ifdef DEBUG
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
#endif

    static char fliped[NUM_MAX];
    int sum = 0;
    int ans = 0;
    int ans_cnt = 0;
    for(k = num; k >= 1; k--) {
        int flag = 1;
        memset(fliped, 0, num);
        ans_cnt = 0;
        sum = 0;
        for(i = 0; i < num; i++) {
            if((arr[i] + sum)%2 == 0) {
                fliped[i] = 1;
                ans_cnt++;
            }
            // arr[i] is 0
            if(i > num-k && fliped[i]) {
                flag = 0; break;
            }
            sum += fliped[i];
            if(i>=(k-1)) sum -= fliped[i-k+1];
#ifdef DEBUG
            printf("%d: i: %d: sum: %d : flip:%d\n",k, i, sum, fliped[i]);
#endif
        }
        if(flag) {
            ans = k;
            break;
        }
    }
    printf("%d %d\n", ans, ans_cnt);
    return 0;
}
