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
    int as, bs;
    int64_t limit;
    cin >> as >> bs >> limit;
    vector<int64_t> arr(as+1);
    vector<int64_t> brr(bs+1);
    for(int i = 0; i < as; i++) {
        cin >> arr[i+1];
    }
    for(int i = 0; i < bs; i++) {
        cin >> brr[i+1];
    }
    // cumulative sum
    for(int i = 1; i <= as; i++) {
        arr[i] += arr[i-1];
    }
    for(int i = 1; i <= bs; i++) {
        brr[i] += brr[i-1];
    }

    int ans = 0;
    for(int i = 0; i <= as; i++) {
        int64_t rem = limit - arr[i];
        if(rem < 0) continue;
        auto pos = upper_bound(brr.begin(), brr.end(), rem);
        int m = pos - brr.begin() - 1;
        ans = max(i + m, ans);
    }
    cout << ans << endl;
    return 0;
}
