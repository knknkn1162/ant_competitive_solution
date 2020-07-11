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
typedef pair<double, double> pdd;
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

#define _x first
#define _y second

struct line {
    pdd base;
    pdd inc;
};

double inner_prod(pdd p1, pdd p2) {
    return (p1._x * p2._x) + (p1._y * p2._y);
}

double norm(pdd p) {
    return sqrt((p._x * p._x) + (p._y * p._y));
}

pdd unit(pdd p) {
    double len = norm(p);
    return make_pair(
        p._x / len,
        p._y / len
    );
}

pdd get_incline(pdd p1, pdd p2) {
    pdd diff = make_pair(
        p2._x - p1._x,
        p2._y - p1._y
    );
    return unit(diff);
}

int main(void) {
    pdd p1;
    pdd p2;
    cin >> p1._x >> p1._y;
    cin >> p2._x >> p2._y;
    struct line lin = (struct line){p1,
        get_incline(p1, p2)
    };

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        pdd p;
        cin >> p._x >> p._y;
        pdd inc = make_pair(
            p._x - lin.base._x,
            p._y - lin.base._y
        );
        // a \dot b
        double len = inner_prod(inc, lin.inc);
        // p1 + diff * lin.inc
        pdd ans = {
            lin.base._x + len * lin.inc._x,
            lin.base._y + len * lin.inc._y
        };
        printf("%.10lf %.10lf\n", ans._x, ans._y);
    }
    return 0;
}
