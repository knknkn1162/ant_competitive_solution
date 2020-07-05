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
#include <cmath>
#define _GLIBCXX_DEBUG // check []
#define DIVISOR 1000000007

using namespace std;
typedef pair<int,bool> pii;
typedef pair<int64_t, int64_t> pII;

template<typename T>
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#define ps(arr) \
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif


int main(void) {
    int num;
    cin >> num;
    vector<vector<pii>> says(num);
    for(int i = 0; i < num; i++) {
        int qs;
        cin >> qs;
        for(int q = 0; q < qs; q++) {
            int x;
            bool y;
            cin >> x >> y;
            // 0-indexed
            x--;
            says[i].push_back(make_pair(x, y));
        }
    }

    int ans = 0;
    for(int pat = 1; pat < (1<< num); pat++) {
        bool is_ok = 1;
        for(int i = 0; i < num; i++) {
            if(!(pat & (1<<i))) continue;
            for(pii p: says[i]) {
                bool real = !!(pat & (1<<p.first));
                bool word = p.second;
                is_ok &= (real == word);
            }
            debug("pat: %d i: %d-> %d\n", pat, i, is_ok);
        }
        if(is_ok) ans = max(ans, __builtin_popcount(pat));
    }

    cout << ans << endl;
    return 0;
}
