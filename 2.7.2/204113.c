#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define NUM_MAX 40
#define BUF_SIZE (NUM_MAX+50)
#define SET_MAX 60

// size: specify sizeof(str)
int get_str(char *str, int size) {
    if(!fgets(str, size, stdin)) return -1;
    return 0;
}

int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
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


void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

int main(void) {
    int sets = get_int();
    static int ans[SET_MAX];
    int aidx = 0;
    int s, i, j;
    for(s = 0; s < sets; s++) {
        int size = get_int();
        static int arr[NUM_MAX];
        static char buf[BUF_SIZE];
        for(i = 0; i < size; i++) {
            get_str(buf, BUF_SIZE);
            for(j = 0; j < size; j++) {
                if(buf[j] == '1') arr[i] = j;
            }
        }
#ifdef DEBUG
        for(i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
#endif

        int cnt = 0;
        ans[aidx++] = cnt;
    }

    for(i = 0; i < aidx; i++) {
        printf("Case #%d: %d\n", i+1, ans[i]);
    }
    return 0;
}
