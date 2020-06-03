#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_int2(int64_t *a1, int64_t *a2) {
  scanf("%lld %lld", a1, a2);
  return 0;
}

void swap(int64_t *a1, int64_t *a2) {
    int64_t tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

#define QUERY_MAX 100

int main(int argc, char const *argv[]){
  int queries = get_int();
  static int64_t ans[QUERY_MAX];
  int aidx = 0;
  int i;
  for(i = 0;i < queries;i++){
      int64_t res;
      int64_t a, b;
      get_int2(&a, &b);
      if(a > b) swap(&a, &b);
      int64_t t=a*b;
      int64_t s=sqrt(0.5 + t);
      if(a+1>=b) {
          res = 2*(s-1);
      // e.g) a1=1, a2=9
      } else if(s*s==t) {
          res = 2*(s-1)-1;
      } else if(s*(s+1)>=t) {
          res=2*(s-1);
      } else { 
          res=2*s-1;
      }
      printf("%lld\n",res);
  }
  for(i = 0; i < aidx; i++) {
      printf("%lld\n", ans[i]);
  }
  return 0;
}
