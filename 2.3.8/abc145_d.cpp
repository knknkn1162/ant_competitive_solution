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

vector<int64_t> factorial;
vector<int64_t> inv_factorial;


pii gcdext(int a, int b) {
    if(a == 0) { return make_pair(0, 1); }
    pii p = gcdext(b%a, a);
    return make_pair(p.second - (b/a) * p.first, p.first);
}

void init_combi(int size) {
    factorial.resize(size+1);
    inv_factorial.resize(size+1);

    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;
    for(int i = 2; i <= size; i++) {
        factorial[i] = (factorial[i-1] * i)%DIVISOR;
        pii p = gcdext(i, DIVISOR);
        int inv = (DIVISOR + p.first)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1] * inv)%DIVISOR;
    }
}

int64_t calc_combi(int n, int k) {
    int64_t res = 1;
    debug("%ld/(%ld * %ld)\n", factorial[n], inv_factorial[n-k], inv_factorial[k]);
    res = (res * factorial[n])%DIVISOR;
    res = (res * inv_factorial[n-k])%DIVISOR;
    res = (res * inv_factorial[k])%DIVISOR;
    return res;
}

int main(void) {
    pii p;
    cin >> p.first >> p.second;
    init_combi(p.first + p.second);

    int64_t res = 0;
    for(int x = 0; x <= p.first; x++) {
        int y = p.first - x;
        if(y%2) continue;
        if(y<0) continue;
        y /= 2;
        if((2*x + y) != p.second) continue;
        debug("%d %d\n", x, y);
        // x+y_C_x
        res = (res + calc_combi(x+y, x))%DIVISOR;
    }

    cout << res << endl;
    return 0;
}
