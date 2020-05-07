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

#define NUM_MAX 100000
#define ANS_MAX (NUM_MAX+1)

int main(void) {
    int sets = get_int();
    int s;
    int i;
    for(s = 0; s < sets; s++) {
        int num, limit;
        static int arr[NUM_MAX];
        memset(arr, 0, sizeof(int)*NUM_MAX);
        get_int2(&num, &limit);
        fget_array(arr, num);

        int sum = 0;
        int left = 0;
        int ans = ANS_MAX;
        for(i = 0; i < num; i++) {
            sum += arr[i];
            if(sum < limit) continue;
#ifdef DEBUG
            printf("%d\n", ans);
#endif
            // move left
            while(left < num) {
                sum -= arr[left++];
                if(sum < limit) {
                    ans = min(ans, i-(left-1)+1);
                    break;
                }
            }
        }
        printf("%d\n", ans == ANS_MAX ? 0 : ans);
    }
    return 0;
}
