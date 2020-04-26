/*
N
A_1 A_2 ... A_N

ex1)
5
2 3 4 5 10
=> 12

ex2)
4
4 5 10 20
0
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 1000

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

#define ARR_SIZE 100

int main(void) {
    int num = get_int();
    int arr[ARR_SIZE];
    fget_array(arr, num);
    int i;
    int sum = 0;
    for(i = num-1; i >= 2; i--) {
        if(arr[i] < arr[i-1] + arr[i-2]) {
            sum = arr[i] + arr[i-1] + arr[i-2];
            break;
        }
    }
    printf("%d\n", sum);
    return 0;
}
