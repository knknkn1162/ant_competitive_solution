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

#define INF (1e+9)

int main(void) {
    int bs, ks;
    cin >> bs >> ks;
    // box, price
    vector<pii> keys(ks);
    for(int i = 0; i < ks; i++) {
        cin >> keys[i].second;
        int types;
        cin >> types;
        int boxes = 0;
        for(int j = 0; j < types; j++) {
            int tmp;
            cin >> tmp;
            // 1-indexed -> 0-indexed
            tmp--;
            boxes |= (1<<tmp);
        }
        keys[i].first = boxes;
        debug("%d -> %d %d\n", i, keys[i].first, keys[i].second);
    }

    vector<vector<int>> dp(ks+1, vector<int>(1<<bs, INF+1));
    dp[0][0] = 0;
    for(int i = 1; i <= ks; i++) {
        pii key = keys[i-1];
        // stay
        for(int pat = 0; pat < (1<<bs); pat++) {
            dp[i][pat] = dp[i-1][pat];
        }
        // choose
        for(int prev = 0; prev < (1<<bs); prev++) {
            int cur = prev | key.first;
            dp[i][cur] = min(
                dp[i-1][prev]+key.second,
                dp[i][cur]
            );
            debug("%d: %d\n",cur, dp[i][cur]);
        }
        debug("dp[%d][%d] = %d\n", i, (1<<bs)-1, 
            dp[i][(1<<bs)-1]
        );
    }
    int ans = dp[ks][(1<<bs)-1];
    if(ans > INF) ans = -1;
    cout << ans << endl;
    return 0;
}
