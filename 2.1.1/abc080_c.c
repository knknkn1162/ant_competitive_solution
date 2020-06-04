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

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;
}

#define SHOP_MAX 100
#define SPOTS 10
#define INF (-(1e+9))

int main(void) {
    int shops = get_int();
    int i;
    static int map[SHOP_MAX][SPOTS];
    for(i = 0; i < shops; i++) {
        fget_array(map[i], SPOTS);
    }

    static int profits[SHOP_MAX][SPOTS+1]; // [shop_idx][cnt]
    for(i = 0; i < shops; i++) {
        fget_array(profits[i], SPOTS+1);
    }

    int pat, shop, bit;
    int ans = INF;
    // At least one of the spot should be opened.
    for(pat = 1; pat < (1<<SPOTS); pat++) {
        int res = 0;
        for(shop = 0; shop < SHOP_MAX; shop++) {
            int cnt = 0;
            for(bit = 0; bit < SPOTS; bit++) {
                if(!(pat & (1<<bit))) continue; // shutdown
                // on sale
                cnt += map[shop][bit];
            }
            res += profits[shop][cnt];
        }
        ans = max(ans, res);
    }
    printf("%d\n", ans);

    return 0;
}
