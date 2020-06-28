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

#define TIME_MAX 3000
int main(void) {
    int num, limit;
    cin >> num >> limit;
    vector<pii> foods(num);
    for(int i = 0; i < num; i++) {
        int time, point;
        cin >> time >> point;
        foods[i] = make_pair(time, point);
    }

    // asc_by_time
    sort(foods.begin(), foods.end());
    vector<vector<int>> dp(num+1, vector<int>(limit+TIME_MAX+1));
    for(int i = 1; i <= num; i++) {
        pii f = foods[i-1];
        // eat
        for(int t = 0; t <= limit+TIME_MAX; t++) {
            dp[i][t] = dp[i-1][t]; // stay
            // slide
            if(t>=0) dp[i][t] = max(dp[i][t-1], dp[i][t]);
            if(t >= f.first && t-f.first<limit) {
                dp[i][t] = max(dp[i][t], dp[i-1][t-f.first]+f.second);
            }
        }
    }

    cout << dp[num][limit+TIME_MAX] << endl;
    return 0;
}
