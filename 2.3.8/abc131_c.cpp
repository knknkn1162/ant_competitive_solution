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

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) { return b; }
    return gcd(b%a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a / gcd(a,b) * b;
}

int main(void) {
    int64_t llimit, ulimit;
    cin >> llimit >> ulimit;
    int64_t whole = ulimit-llimit+1;
    llimit--;
    int64_t a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    int64_t ab = lcm(a, b);
    debug("lcm: %ld\n", ab);
    // principle of inclusion and exclusion
    int64_t right = ulimit/a + ulimit/b - ulimit/ab;
    int64_t left = llimit/a + llimit/b - llimit/ab;
    cout << whole - (right-left) << endl;
    return 0;
}
