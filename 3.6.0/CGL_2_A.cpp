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

struct line {
    pii p1;
    pii incline;
};


enum type {
    TYPE_NONE,
    TYPE_ORTHOGONAL,
    TYPE_PARALLEL,
};

#define _x first
#define _y second

int inner_prod(pii p1, pii p2) {
    return (p1._x * p2._x) + (p1._y * p2._y);
}

int outer_prod(pii p1, pii p2) {
    return (p1._x * p2._y) - (p1._y * p2._x);
}

int main(void) {
    pii p1;
    pii p2;
    int num;
    cin >> num;
    for(int n = 0; n < num; n++) {
        cin >> p1.first >> p1.second;
        cin >> p2.first >> p2.second;
        pii inc1 = make_pair(p2.first - p1.first,
            p2.second - p1.second
        );
        cin >> p1.first >> p1.second;
        cin >> p2.first >> p2.second;
        pii inc2 = make_pair(
            p2.first - p1.first,
            p2.second - p1.second
        );
        int type = 0;
        if(!inner_prod(inc1, inc2)) {
            type = TYPE_ORTHOGONAL;
        } else if (!outer_prod(inc1, inc2)) {
            type = TYPE_PARALLEL;
        } else {
            type = TYPE_NONE;
        }
        cout << type << endl;
    }

    return 0;
}
