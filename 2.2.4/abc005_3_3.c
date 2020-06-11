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
struct thing {
    int time;
    int type;
};

enum type {
    TYPE_TAKO,
    TYPE_GUEST,
};

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(struct thing *arr, int type, int size) {
    int i;
    for(i = 0; i < size; i++) {
        int time;
        scanf("%d", &time);
        arr[i] = (struct thing){time, type};

    }
    return 0;
}

#define NUM_MAX 100
#define QUERY_MAX 100
int asc(const void *a1, const void *a2) {
    struct thing *t1 = (struct thing*)a1;
    struct thing *t2 = (struct thing*)a2;
    if(t1->time == t2->time) {
        // TAKO first!
        return t1->type - t2->type;
    }
    return t1->time - t2->time;
}

int queue[NUM_MAX*2];
int start;
int end;

int is_empty(void) {
    return start == end;
}

void enqueue(int val) {
    queue[start++] = val;
}

int dequeue(void) {
    return queue[end++];
}

int main(void) {
    int tlimit = get_int();
    int num = get_int();

    static struct thing ts[NUM_MAX*2];
    fget_array(ts, TYPE_TAKO, num);
    int qs = get_int();
    fget_array(&ts[num], TYPE_GUEST, qs);

    int size = qs + num;
    qsort(ts, size, sizeof(struct thing), asc);

    int ans = 1;
    int i;
    for(i = 0; i < size; i++) {
        struct thing t = ts[i];
        switch(t.type) {
            case TYPE_TAKO:
                enqueue(t.time+tlimit);
                break;
            case TYPE_GUEST:
                {
                    int ok = 0;
                    while(!is_empty()) {
                        // Takoyaki is in time!
                        if(t.time <= dequeue()) { ok=1; break; }
                    }
                    if(!ok) ans = 0;
                }
                break;
            default:
                break;
        }
        if(!ans) break;
    }
    printf("%s\n", ans ? "yes" : "no");
    return 0;
}
