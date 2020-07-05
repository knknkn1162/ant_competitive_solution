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


int main(void) {
    int64_t sum;
    cin >> sum;
    if(sum <= (1e+9)) {
        cout << 0 << " " << 0 << " ";
        cout << sum << " " << 0 << " ";
        cout << sum << " " << 1 << endl;
        return 0;
    }
    int64_t p = sqrt(-100+sum);
    debug("%d\n", p);
    pii p1 = make_pair(0, 0);
    int64_t x = p; int64_t y = p+1;
    int64_t rem = x*y - sum;
    if(rem < 0) {
        rem += y;
        x++;
    }
    pii p2 = make_pair(x, rem);
    pii p3 = make_pair(1, y);

    cout << p1.first << " " << p1.second << " ";
    cout << p2.first << " " << p2.second << " ";
    cout << p3.first << " " << p3.second << endl;
    return 0;
}
