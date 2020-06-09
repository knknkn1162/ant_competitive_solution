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
#define POINT_MAX (NUM_MAX*10)

struct point2d {
    int x;
    int y;
};

int asc(const void *a1, const void *a2) {
    struct point2d *p1 = (struct point2d*)a1;
    struct point2d *p2 = (struct point2d*)a2;
    if(p1->x == p2->x) {
        return p1->y - p2->y;
    }
    return p1->x - p2->x;
}

int check(struct point2d p, int row, int col) {
    if(p.x < 0 || p.y < 0) return 0;
    if(p.x >= row-2 || p.y >= col-2) return 0;
    return 1;
}

#define HASH_SIZE 65536

struct list {
    struct point2d p;
    int idx;
    struct list *next;
};

struct list *create_htable(void) {
    static struct list htable[HASH_SIZE];
    int i;
    for(i = 0; i < HASH_SIZE; i++) {
        htable[i].next = &htable[i];
    }
    return htable;
}

int is_equal(struct point2d p1, struct point2d p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int get_key(struct point2d p) {
    return (p.x*p.y+p.x+p.y) & (HASH_SIZE-1);
}

struct list* find(struct list *htable, struct point2d p) {
    struct list *head = &htable[get_key(p)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(is_equal(elem->p, p)) {
            return elem;
        }
    }
    return NULL;
}

void add_elem(struct list *htable, struct point2d p) {
    struct list *elem = malloc(sizeof(struct list));
    struct list *head = &htable[get_key(p)];
    elem->next = head->next;
    elem->p = p;
    head->next = elem;
}

int main(void) {
    int row, col, num;
    get_int2(&row, &col);
    num = get_int();
    int i, j, k;
    struct list* htable = create_htable();
    static struct point2d cands[POINT_MAX];
    int cidx = 0;
    for(k = 0; k < num; k++) {
        int x, y;
        get_int2(&x, &y);
        // 1-indexed -> 0-indexed
        x--; y--;
        add_elem(htable, (struct point2d){x, y});
        // put into stack
        for(i = 0; i <= 2; i++) {
            for(j = 0; j <= 2; j++) {
                struct point2d np = (struct point2d){x-i, y-j};
                if(check(np, row, col)) cands[cidx++] = np;
            }
        }
    }
    qsort(cands, cidx, sizeof(struct point2d), asc);

    static int64_t map[10];
    int64_t total = 0;
    struct point2d prev = {-1, -1};
    for(k = 0; k < cidx; k++) {
        struct point2d cur = cands[k];
        if(is_equal(cur, prev)) continue;
        total++;
        int cnt = 0;
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                struct point2d np = {cur.x+i, cur.y+j};
                cnt += (find(htable, np) != NULL);
            }
        }
        map[cnt]++;
        prev = cur;
    }
    int64_t rem = (int64_t)(row-2)*(col-2) - total;
    map[0] += rem;
    for(i = 0; i < 10; i++) {
        printf("%lld\n", map[i]);
    }
    return 0;
}
