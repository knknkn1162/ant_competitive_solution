#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define BUF_SIZE 10

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

#define NUM_MAX 10
#define ARR_MAX (10*9*8*7)

int asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// in-place
void reversed(int *arr, int size) {
    if(size==0 || size==1) return;
    static int brr[NUM_MAX] = {0};
    memcpy(brr, arr, size*sizeof(int));
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = brr[size-1-i];
    }
}

int next_permutation(int *arr, int size) {
    int i, j;
    if(size==0 || size==1) return 0;
    for(i = size-2; i >= 0; i--) {
        if(arr[i+1] > arr[i]) break;
    }
    if(i<0) {
        reversed(arr, size);
        return 0;
    }
    // search lower bound of arr[i];
    for(j = size-1; j >= 0; j--) {
        if(arr[i] < arr[j]) break;
    }
#ifdef DEBUG
    int k;
    printf("perm: %d <-> %d\n", i, j);
#endif
    swap(&arr[i], &arr[j]);
    reversed(&arr[i+1], size-1-i);
    return 1;
}

int get_index(int pat, int bits, int *irr, int size) {
    int i;
    int idx = 0;
    for(i = 0; i < bits; i++) {
        if(!(pat & (1<<i))) continue;
        irr[idx++] = i;
    }
    return 0;
}

int main(void) {
    int num = get_int();
    int k = get_int();
    static int cards[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        cards[i] = get_int();
    }
    int irr[NUM_MAX];
    static int numbers[ARR_MAX];
    int nidx = 0;
    int pat;
    for(pat = 1; pat < (1<<num); pat++) {
        if(__builtin_popcount(pat)!=k) continue;
        get_index(pat, NUM_MAX, irr, k);

        // permutation from different k number
        do {
#ifdef DEBUG
            for(i = 0; i < k; i++) printf("%d ", irr[i]);
            putchar('\n');
#endif
            int gen = 0;
            for(i = 0; i < k; i++) {
                int card = cards[irr[i]];
                gen = (card >= 10) ? gen*100 : gen*10;
                gen += card;
            }
            numbers[nidx++] = gen;
        } while(next_permutation(irr, k));
    }

    // counting
    qsort(numbers, nidx, sizeof(int), asc);
    int cnt = 1;
    int prev = numbers[0];
    for(i = 1; i < nidx; i++) {
        int cur = numbers[i];
        if(cur == prev) continue;
        cnt++;
        prev = cur;
    }
    printf("%d\n", cnt);
    return 0;
}
