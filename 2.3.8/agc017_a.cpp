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
#define ps(arr) \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

#define VAL_MAX 100
int main(void) {
    int num; int rem;
    cin >> num >> rem;
    vector<int> arr(num);
    cins(arr);

    vector<vector<int64_t>> dp(num+1, vector<int64_t>(num*VAL_MAX+1));
    dp[0][0] = 1;
    for(int i = 1; i <= num; i++) {
        for(int j = 0; j <= num*VAL_MAX; j++) {
            int val = arr[i-1];
            dp[i][j] += dp[i-1][j];
            if(j >= val) dp[i][j] += dp[i-1][j-val];
        }
    }
    int64_t ans = 0;
    for(int i = rem; i <= num*VAL_MAX; i+=2) {
        debug("%d -> %lld\n", i, dp[num][i]);
        ans += dp[num][i];
    }
    cout << ans << endl;
    return 0;
}
