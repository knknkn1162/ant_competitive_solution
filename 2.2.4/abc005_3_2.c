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
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define NUM_MAX 100
#define GUEST_MAX 100

int check(int tako, int guest, int tlimit) {
    // guests are too early to come
    if(guest < tako) return 0;
    // tako is too old to serve
    if(tako + tlimit < guest) return 0;
    return 1;
}

int main(void) {
    int tlimit = get_int();
    int ns = get_int();
    static int takos[NUM_MAX+1];
    fget_array(takos, ns);
    takos[ns] = 1000; // guard
    int ps = get_int();
    static int guests[GUEST_MAX];
    fget_array(guests, ps);
    int n;
    int i = 0;
    int flag = 1;
    for(n = 0; n < ps; n++) {
        int g = guests[n];
        int is_serve = 0;
        for(; i < ns+1; i++) {
            if(is_serve) break;
            // step forward( trash takoyaki )
            if(takos[i] + tlimit < g) continue;
            if(!check(takos[i], g, tlimit)) flag = 0;
            is_serve = 1;
        }
        if(!flag) break;
    }
    printf("%s\n", flag ? "yes" : "no");
    return 0;
}
