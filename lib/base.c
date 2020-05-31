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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

int get_int5(int *a1, int *a2, int *a3, int *a4, int *a5) {
  scanf("%d %d %d %d %d", a1, a2, a3, a4, a5);
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

char get_char(void) {
    char buf[3];
    scanf("%s", buf);
    return buf[0];
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

// sort
int asc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return 1;
    if(aa1 == aa2) return 0;
    return -1;
}
