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

int get_str(char *str, int size)
{
    char format[100];
    if (size == 0)
        return 0;
    snprintf(format, sizeof(format), "%%%ds", size);
    scanf(format, str);
    return 0;
}

#define NUM_MAX 100000

enum type {
    TYPE_WOLF,
    TYPE_SHEEP
};

enum reply {
    REPLY_X,
    REPLY_O,
};

static char type_table[2] = {
    [TYPE_WOLF] = 'W',
    [TYPE_SHEEP] = 'S'
};

static char reply_table[256] = {
    ['o'] = REPLY_O,
    ['x'] = REPLY_X
};

// right = [cur][reply][left]
static char next[2][2][2] = {
    // I'm wolf
    {
        // says 'x'
        {
            // When left is TYPE_WOLF
            TYPE_WOLF,
            // left is TYPE_SHEEP
            TYPE_SHEEP
        },
        // says 'o'
        {
            // When left is TYPE_WOLF
            TYPE_SHEEP,
            TYPE_WOLF,
        },
    },
    // I'm sheep
    {
        // says 'x'
        {
            TYPE_SHEEP,
            TYPE_WOLF,
        },
        // says 'o'
        {
            TYPE_WOLF,
            TYPE_SHEEP,
        },
    },
};

int main(void) {
    int num = get_int();
    static char str[NUM_MAX];
    get_str(str, num);

    int t, i;
    int ok = 0;
    static char types[NUM_MAX];
    for(t = 0; t < 4; t++) {
        memset(types, 0, NUM_MAX);
        // 0: wolf 1: sheep
        types[0] = !!(t&1);
        types[1] = !!(t&2);
        int flag = 1;
        for(i = 1; i <= num; i++) {
            int cur = i%num;
            int left = (i+num-1)%num;
            int right = (i+num+1)%num;
            int cur_type = types[cur];
            int reply = reply_table[str[cur]];
            int next_type = next[cur_type][reply][types[left]];
            if(i >= num-1) {
                if(next_type != types[right]) {
                    flag = 0;
                    break;
                }
            }
            types[right] = next_type;
        }
        if(flag) { ok=1; break; }
    }

    if(ok) {
        for(i = 0; i < num; i++) {
            putchar(type_table[types[i]]);
        }
    } else {
        printf("%d", -1);
    }
    putchar('\n');
    return 0;
}
