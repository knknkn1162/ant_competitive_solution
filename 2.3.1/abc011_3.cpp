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

#define MAX_COUNT 100
int main(void) {
    int num;
    cin >> num;
    vector<int> dp(num+1, MAX_COUNT+1);
    dp[num] = 0;
    vector<bool> ok(num+1, 1);
    for(int i = 0; i < 3; i++) {
        int ng;
        cin >> ng;
        ok[ng] = 0;
    }
    for(int i = num; i >= 0; i--) {
        if(!ok[i]) continue;
        for(int j = 1; j <= 3; j++) {
            if(i+j > num) continue;
            if(!ok[i+j]) continue;
            dp[i] = min(dp[i+j]+1, dp[i]);
        }
    }
    cout << (dp[0] > MAX_COUNT ? "NO" : "YES") << endl;
    return 0;
}
