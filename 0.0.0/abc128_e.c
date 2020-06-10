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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

#define NUM_MAX 200000
#define QUERY_MAX 200000

struct event {
    int flag;
    int time;
    int pos;
};

int asc_by_time(const void *a1, const void *a2) {
    struct event *e1 = (struct event*)a1;
    struct event *e2 = (struct event*)a2;
    return e1->time - e2->time;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
#define INF (2e+9)

int main(void) {
    int num, qs;
    get_int2(&num, &qs);
    int i;
    static struct event events[NUM_MAX*2+2];
    static int eidx = 0;
    events[0] = (struct event){1, -INF, INF};
    for(i = 0; i < num; i++) {
        int start, end, pos;
        get_int3(&start, &end, &pos);
        start -= pos;
        end -= pos;
        events[eidx++] = (struct event){1, start, pos};
        events[eidx++] = (struct event){-1, end, pos};
    }
    events[eidx++] = (struct event){1, INF, INF};

    for(i = 0; i < qs; i++) {
        int time = get_int();
        events[eidx++] = (struct event){0, time, 0};
    }
    qsort(events, eidx, sizeof(struct event), asc_by_time);

    int mmin = INF;
    static int ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < eidx; i++) {
        struct event e = events[i];
        if(!e.flag) {
            ans[aidx++] = mmin;
            continue;
        }
        // TODO: set like data structure
        if(e.flag == 1) {
            insert(e.pos);
        } else if (e.flag == -1) {
            delete(e.pos);
        }
        mmin = peek_min();
    }


    // presentation
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
