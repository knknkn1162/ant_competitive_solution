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

int main(void) {
    int n, m;
    cin >> n >> m;
    if(abs(n-m)>=2) {
        cout << 0 << endl;
        return 0;
    }
    int size = max(m, n);
    vector<int64_t> factorial(size+1);
    factorial[0] = factorial[1] = 1;
    for(int i = 2; i <= size; i++) {
        factorial[i] = (factorial[i-1]*i)%DIVISOR;
    }

    if(n > m) swap(n, m);
    // assume that n <= m
    // A B A B A

    int64_t res = 1;
    res = (res * factorial[n])%DIVISOR;
    res = (res * factorial[m])%DIVISOR;
    if(n == m) {
        res = (res * 2)%DIVISOR;
    }
    cout << res << endl;
    return 0;
}
