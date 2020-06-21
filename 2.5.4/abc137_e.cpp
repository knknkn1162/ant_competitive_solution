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

struct edge {
    int src;
    int dst;
    int coins;
};

#define INF ((1e+9)+1)

int main(void) {
    int vs, es, penalties;
    cin >> vs >> es >> penalties;
    vector<struct edge> edges(es);
    for(auto& e: edges) {
        int src, dst, coins;
        cin >> src >> dst >> coins;
        // inverse for bellman-ford
        e = (struct edge){src-1, dst-1, -(coins-penalties)};
    }

    vector<int> coins(vs, INF);
    coins[0] = 0;
    // Bellman Ford algorithm
    for(int i = 0; i < vs-1; i++) {
        for(int j = 0; j < es; j++) {
            struct edge e = edges[j];
            if(coins[e.src] == INF) continue;
            int nnew = coins[e.src] + e.coins;
            coins[e.dst] = min(nnew, coins[e.dst]);
        }
    }
    // ans: -coins[vs-1]
    int ans = max(0, -coins[vs-1]);
    debug("ans: %d\n", ans);

    // sanity check
    vector<char> check_negative(vs);
    for(int i = 0; i < vs; i++) {
        for(auto& e: edges) {
            if(coins[e.src] == INF) continue;
            int nnew = coins[e.src] + e.coins;
            if(nnew < coins[e.dst]) {
                check_negative[e.dst] = 1;
                coins[e.dst] = nnew;
            }
            if(check_negative[e.src]) {
                check_negative[e.dst] = 1;
            }
        }
    }
    cout << (check_negative[vs-1] ? -1 : ans) << endl;
    return 0;
}
