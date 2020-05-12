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

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

#define COORD_MAX (1e+9)
#define NUM_MAX 2000
#define COMP_X_MAX (NUM_MAX*2+2)
#define COMP_Y_MAX (NUM_MAX*2+2)

// [start, end)
struct range {
    int start;
    int end;
};

struct point2d {
    int x;
    int y;
};

int asc(const void *a1, const void *a2) {
    return *(int*)a1 - *(int*)a2;
}

#define HASH_SIZE 65536
struct list {
    int num;
    int idx;
    struct list *next;
};

struct list *create_htable(void) {
    static struct list htable[HASH_SIZE];
    int i;
    for(i = 0; i < HASH_SIZE; i++) {
        htable[i].next = &htable[i];
        htable[i].idx = htable[i].num = 0;
    }
    return htable;
}

int get_key(int num) {
    return num & (HASH_SIZE-1);
}

int find_idx(struct list *htable, int num) {
    struct list *head = &htable[get_key(num)];
    struct list *elem;
    for(elem = head->next; elem != head; elem = elem->next) {
        if(elem->num == num) {
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

int compress(struct range *rs, int num, int64_t *unzip) {
    struct list *zip = create_htable();
    int i;
    static int arr[COMP_X_MAX];
    memset(arr, 0, sizeof(int)*COMP_X_MAX);
    int idx = 0;
    for(i = 0; i < num; i++) {
        arr[idx++] = rs[i].start;
        arr[idx++] = rs[i].end;
    }
    qsort(arr, idx, sizeof(int), asc);
    int prev = COORD_MAX+1;
    int cidx = 1;
    for(i = 0; i < idx; i++) {
        if(prev == arr[i]) continue;
        add_elem(zip, arr[i], cidx);
        unzip[cidx] = arr[i];
        prev = arr[i];
        cidx++;
    }
    for(i = 0; i < num; i++) {
        rs[i].start = find_idx(zip, rs[i].start);
        rs[i].end = find_idx(zip, rs[i].end);
    }
    return cidx;
}


int main(void) {
    int num = get_int();
    int i, j;
    struct range rxs[NUM_MAX];
    struct range rys[NUM_MAX];
    for(i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        get_int4(&x1, &y1, &x2, &y2);
        rxs[i] = (struct range){x1, x2};
        rys[i] = (struct range){y1, y2};
    }

    static int64_t unzip_x[COMP_X_MAX];
    static int64_t unzip_y[COMP_Y_MAX];
    struct point2d size = {
        compress(rxs, num, unzip_x),
        compress(rys, num, unzip_y)
    };

    static char map[COMP_X_MAX+2][COMP_Y_MAX+2];
    int k1, k2;
    for(i = 0; i < num; i++) {
        struct range rx = rxs[i];
        struct range ry = rys[i];
        for(k1 = rx.start; k1 < rx.end; k1++) {
            for(k2 = ry.start; k2 < ry.end; k2++) {
                map[k1][k2] = 1;
            }
        }
    }
#ifdef DEBUG
    for(i = 1; i <= size.x; i++) {
        for(j = 1; j <= size.y; j++) {
            printf("%d", map[i][j]);
        }
        putchar('\n');
    }
#endif

    int64_t area = 0;
    for(i = 1; i <= size.x; i++) {
        for(j = 1; j <= size.y; j++) {
            if(!map[i][j]) continue;
            int64_t dx = unzip_x[i+1] - unzip_x[i];
            int64_t dy = unzip_y[j+1] - unzip_y[j];
            area += dx * dy;
        }
    }
    printf("%lld\n", area);

    return 0;
}
