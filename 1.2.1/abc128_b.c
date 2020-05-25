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

int get_strint2(char *a1, int *a2) {
  scanf("%s %d", a1, a2);
  return 0;
}

#define NAME_MAX 15
struct store {
    char name[NAME_MAX];
    int score;
    int id;
};

#define NUM_MAX 100

int asc_by_name(const void *a1, const void *a2) {
    struct store *s1 = (struct store*)a1;
    struct store *s2 = (struct store*)a2;

    int cmp = strncmp(s1->name, s2->name, NAME_MAX);
    if(cmp) return cmp;
    return s2->score - s1->score;
}

int main(void) {
    int num = get_int();
    struct store stores[NUM_MAX];
    int i;
    for(i = 0; i < num; i++) {
        get_strint2(stores[i].name, &stores[i].score);
        stores[i].id = i+1;
    }

    qsort(stores, num, sizeof(struct store), asc_by_name);

    for(i = 0; i < num; i++) {
        printf("%d\n", stores[i].id);
    }

    return 0;
}
