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

#define INF (1e+13)

int64_t calc_ms(vector<int>& arr, vector<int64_t>& foods, int64_t key) {
    int num = arr.size();
    vector<int64_t> after(num);
    for(int i = 0; i < num; i++) {
        after[i] = key / foods[i];
    }
    sort(after.begin(), after.end());
    ps(arr); ps(after);
    int64_t ans = 0;
    for(int i = 0; i < num; i++) {
        ans += max(arr[i] - after[i], (int64_t)0);
    }
    debug("%lld -> %lld\n", key, ans);
    return ans;
}

int main(void) {
    int num;
    int64_t k;
    cin >> num >> k;
    vector<int> arr(num);
    cins(arr);
    sort(arr.begin(), arr.end());
    vector<int64_t> foods(num);
    cins(foods);

    int64_t low = -1;
    int64_t high = INF;
    while(low + 1 < high) {
        int64_t mid = (low + high) / 2;
        if(calc_ms(arr, foods, mid) <= k) {
            high = mid;
        } else {
            low = mid;
        }
        debug("%lld %lld %lld\n", low, mid, high);
    }
    cout << high << endl;
    return 0;
}
