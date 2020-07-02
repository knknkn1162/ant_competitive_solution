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


#define NUM_2_MAX 1000000
#define INF (1e+12)

int64_t power(int64_t val, int num) {
    if(val > NUM_2_MAX) {
        return num == 1 ? val : INF+1;
    }
    int64_t ans = 1;
    while(num--) {
        if(ans > INF) return INF+1;
        ans *= val;
    }
    return ans;
}

int main(void) {
    int64_t num, prod;
    cin >> num >> prod;
    int prod_2 = sqrt(0.5 + prod);
    int64_t ans = 1;
    if(num == 1) {
        cout << prod << endl;
        return 0;
    }
    for(int div = 2; div <= prod_2; div++) {
        int64_t est;
        if(prod%div) continue;
        est = power(prod/div, num);
        if(prod%est == 0) { ans = prod/div; break; }
        est = power(div, num);
        if(prod%est == 0) ans = div;
    }
    cout << ans << endl;
    return 0;
}
