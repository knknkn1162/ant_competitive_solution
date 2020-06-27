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

#define TYPES 10
int main(void) {
    int num, selects;
    cin >> num >> selects;
    vector<vector<int>> cum(TYPES);
    // cum[i] is 1-indexed
    for(int i = 0; i < TYPES; i++) {
        cum[i].push_back(0);
    }
    for(int i = 0; i < num; i++) {
        int price, type;
        cin >> price >> type;
        // 1-indexed -> 0-indexed
        type--;
        cum[type].push_back(price);
    }
    for(int i = 0; i < TYPES; i++) {
        sort(cum[i].begin()+1, cum[i].end(), greater<int>());
    }

    // calc cumulative sum
    for(int i = 0; i < TYPES; i++) {
        for(int j = 1; j < cum[i].size(); j++) {
            cum[i][j] += cum[i][j-1];
        }
        for(int j = 1; j < cum[i].size(); j++) {
            int bonus = j * (j-1);
            cum[i][j] += bonus;
            debug("cum[%d][%d] = %d\n", i, j, cum[i][j]);
        }
    }

    vector<vector<int>> dp(num+1, vector<int>(num+1));
    int prev = 0;
    for(int type = 0; type < TYPES; type++) {
        int cnt = cum[type].size() - 1;
        int cur = prev + cnt;
        // DP: N**2
        for(int i = 0; i <= selects; i++) {
            for(int j = 0; j <= cnt; j++) {
                if(i-j < 0) continue;
                int nnew = dp[prev][i-j] + cum[type][j];
                dp[cur][i] = max(nnew, dp[cur][i]);
            }
        }
        debug("[type: %d] dp[%d][%d] = %d\n", type, cur, selects, dp[cur][selects]);
        prev = cur;
    }
    cout << dp[num][selects] << endl;

    return 0;
}
