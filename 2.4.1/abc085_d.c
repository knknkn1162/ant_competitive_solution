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

#define NUM_MAX 100000

struct katana {
    int cut;
    int throw;
};

int desc_by_throw(const void *a1, const void *a2) {
    struct katana *k1 = (struct katana*)a1;
    struct katana *k2 = (struct katana*)a2;
    return k2->throw - k1->throw;
}

int main(void) {
    int ks, hp;
    get_int2(&ks, &hp);
    static struct katana katanas[NUM_MAX+1];

    int i;
    int cut_max = 0;
    for(i = 0; i < ks; i++) {
        get_int2(&katanas[i].cut, &katanas[i].throw);
        cut_max = max(cut_max, katanas[i].cut);
    }
    katanas[ks] = (struct katana){cut_max, cut_max};
    qsort(katanas, ks+1, sizeof(struct katana), desc_by_throw);

    int cnt = 0;
    for(i = 0; i < ks+1; i++) {
        if(hp<=0) break;
        // attack the enemy by cut until we defeat it.
        if(katanas[i].throw == cut_max) {
            cnt += (hp-1)/cut_max + 1;
            break;
        } else {
            hp -= katanas[i].throw;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
