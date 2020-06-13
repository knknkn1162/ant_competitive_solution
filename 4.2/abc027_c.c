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

enum strategy {
    ENUM_SMALLER,
    ENUM_BIGGER,
};

enum turn {
    ENUM_TAKA,
    ENUM_AOKI,
};

char turn_table[2][15] = {
    "Takahashi",
    "Aoki",
};

int calc_digits(int64_t num, int base) {
    int ds = 0;
    while(num) {
        num /= base;
        ds++;
    }
    return ds;
}

int main(void) {
    int64_t num;
    scanf("%lld", &num);

    int ds = calc_digits(num, 2);
    int taka_strategy = (ds%2);
    int aoki_strategy = (1-taka_strategy);

    int64_t k = 1;
    int turn = 0; // taka
    while(k<=num) {
        if(turn == ENUM_TAKA) {
            k *= 2;
            if(taka_strategy == ENUM_BIGGER) k += 1;
        } else {
            k *= 2;
            if(aoki_strategy == ENUM_BIGGER) k += 1;
        }
#ifdef DEBUG
        printf("%lld\n", k);
#endif
        turn = (1-turn);
    }

    printf("%s\n", turn_table[turn]);

    return 0;
}
