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

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T>& arr) { for(T e: arr) p(e); }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

int main(void) {
    int num, start, goal;
    cin >> num;
    cin >> start >> goal;
    // 1-indexed -> 0-indexed
    start--; goal--;
    vector<vector<int>> dp(num+1, vector<int>(num+1));

    vector<vector<int>> graph(num);
    int es;
    cin >> es;
    for(int i = 0; i < es; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        // 1-indexed -> 0-indexed
        v1--; v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    debug("ok%d\n", 1);
    dp[0][start] = 1;
    int ans = 0;
    for(int i = 1; i <= num; i++) {
        for(int node = 0; node < num; node++) {
            for(int dst: graph[node]) {
                dp[i][dst] = (dp[i][dst] + dp[i-1][node])%DIVISOR;
            }
        }
        if(dp[i][goal]) {
            ans = dp[i][goal];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
