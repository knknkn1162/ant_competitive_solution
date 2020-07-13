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
typedef pair<int,int> pii;
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


#define SCORE_MAX 1000000
int main(void) {
    int num;
    cin >> num;
    vector<int> cum(SCORE_MAX+1);
    for(int i = 0; i < num; i++) {
        int val;
        cin >> val;
        cum[val]++;
    }
    for(int i = 1; i <= SCORE_MAX; i++) {
        cum[i] += cum[i-1];
    }
    int qs;
    cin >> qs;

    for(int i = 0; i < qs; i++) {
        int q;
        cin >> q;
        int key = num-q;
        auto pos = lower_bound(cum.begin(), cum.end(), key);
        debug("%d\n", cum[pos-cum.begin()]);
        int ans = pos - cum.begin() + 1;
        if(ans == 1) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
