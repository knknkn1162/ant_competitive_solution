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
#include <cmath> // sqrt
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

int get_digit_sum(int64_t num) {
    int ans = 0;
    while(num) {
        ans += (num%10);
        num /= 10;
    }
    return ans;
}

// 9...9 -> 18*9 < 20*9
#define F_MAX 200
int main(void) {
    int64_t num;
    cin >> num;
    vector<int64_t> ans;
    for(int64_t x = num-1; x >= max<int64_t>(num-F_MAX, 0); x--) {
        int64_t res = get_digit_sum(x) + x;
        if(res == num) ans.push_back(x);
    }

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto e: ans) {
        cout << e << endl;
    }
    return 0;
}
