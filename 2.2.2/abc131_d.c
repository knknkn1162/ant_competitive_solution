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

struct work {
    int cost;
    int deadline;
};


int asc_by_deadline(const void *a1, const void *a2) {
    struct work *w1 = (struct work*)a1;
    struct work *w2 = (struct work*)a2;
    if(w1->deadline == w2->deadline) {
        return w2->cost - w1->cost;
    } 
    return w1->deadline - w2->deadline;
    
}

#define NUM_MAX 200000

int main(void) {
    int num = get_int();

    int i;
    static struct work works[NUM_MAX];
    for(i = 0; i < num; i++) {
        get_int2(&works[i].cost, &works[i].deadline);
    }

    qsort(works, num, sizeof(struct work), asc_by_deadline);

    int64_t time = 0;
    int flag = 1;
    for(i = 0; i < num; i++) {
        struct work cur = works[i];
        time += cur.cost;
#ifdef DEBUG
        printf("cur time: %lld\n", time);
#endif
        if(time > cur.deadline) {
            flag = 0;
            break;
        }
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}
