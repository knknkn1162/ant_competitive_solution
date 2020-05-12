#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

#define PREF_MAX 100000
#define CITY_MAX 100000

struct city {
    int pref;
    int year;
};

int asc_by_year(const void *a1, const void *a2) {
    struct city *ca1 = (struct city*)a1;
    struct city *ca2 = (struct city*)a2;
    return ca1->year - ca2->year;
}

struct list {
    int num;
    int idx;
    struct list *next;
};

#define HASH_SIZE 65536
struct list *create_htable(void) {
    static struct list htable[HASH_SIZE];
    int i;
    for(i = 0; i < HASH_SIZE; i++) {
        htable[i].next = &htable[i];
    }
    return htable;
}

int get_key(int num) {
    return num & (HASH_SIZE-1);
}

int find_idx(struct list *htable, struct city *c) {
    struct list *head = &htable[get_key(c->year)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->num == c->year) {
            return elem->idx;
        }
    }
    return -1;
}

void add_elem(struct list *htable, int num, int idx) {
    struct list *elem = malloc(sizeof(struct list));
    struct list *head = &htable[get_key(num)];
    elem->next = head->next;
    elem->num = num;
    elem->idx = idx;
    head->next = elem;
}

void zip(struct list *htable, struct city *cities, int size) {
    qsort(cities, size, sizeof(struct city), asc_by_year);
    int prev = 0;
    int i;
    static int idx[PREF_MAX+1];
    for(i = 0; i <= PREF_MAX; i++) idx[i] = 1;

    for(i = 0; i < size; i++) {
        int y = cities[i].year;
        int pref = cities[i].pref;
        // There are no multiple cities that are established in the same year.
        if(prev == y) continue;
        add_elem(htable, y, idx[pref]);
        prev = y;
        idx[pref]++;
    }
    return;
}

int main(void) {
    int num, cs;
    get_int2(&num, &cs);
    static struct city cities[CITY_MAX];

    int i;
    for(i = 0; i < cs; i++) {
        get_int2(&cities[i].pref, &cities[i].year);
    }
    static struct city sorted[CITY_MAX];
    memcpy(sorted, cities, sizeof(struct city)*cs);

    struct list *htable = create_htable();
    zip(htable, sorted, cs);

    for(i = 0; i < cs; i++) {
        struct city c = cities[i];
        printf("%06d%06d\n", c.pref, find_idx(htable, &c));
    }
    return 0;
}
