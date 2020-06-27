#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#define _GLIBCXX_DEBUG // check []
#define DIVISOR 1000000007

using namespace std;
typedef pair<int,int> pii;
typedef pair<int64_t, int64_t> pII;

template<typename T>
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

struct meal {
    int64_t cost;
    int64_t recovery;
};

#define INF (1e+17)
int main(void) {
    int64_t num;
    int64_t hp;
    cin >> num >> hp;
    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    vector<struct meal> ms(2);
    ms[0] = {a,b+e};
    ms[1] = {c,d+e};
    int64_t start = hp-(int64_t)num*e;
    if(start > 0) {
        cout << 0 << endl;
        return 0;
    }
    // need to recover <start> point
    start = abs(start) + 1;
    debug("%lld\n", start);
    int64_t ans = ms[0].cost*num;
    for(int64_t d1 = 0; d1 <= num; d1++) {
        int64_t recovery = ms[0].recovery * d1;
        int64_t d2 = max((int64_t)0, (start-recovery-1)/ms[1].recovery+1);
        if(d1+d2 > num) continue;
        debug("%d+%d+%d\n", d1, d2, num-d1-d2);
        int64_t res = ms[0].cost * d1 + ms[1].cost * d2;
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
