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

int64_t get_gcd(int a, int b) {
    if(a == 0) { return b; }
    return get_gcd(b%a, a);
}

int main(void) {
    int num, k;
    cin >> num >> k;
    vector<int> arr(num);
    cins(arr);

    int res = 0;
    int mmax = 0;
    for(int i = 0; i < num; i++) {
        int val = arr[i];
        mmax = max(val, mmax);
        if(res > val) swap(res, val);
        res = get_gcd(res, arr[i]);
    }
    debug("gcd: %d\n", res);
    bool flag = 0;
    if(k > mmax) {
        flag = false;
    } else {
        flag = ((mmax-k)%res == 0);
    } 

    cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
