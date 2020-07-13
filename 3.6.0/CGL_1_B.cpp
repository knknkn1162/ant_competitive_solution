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

double norm(pdd p) {
    return sqrt((p._x * p._x) + (p._y * p._y));
}

class Line {
public:
    pdd base;
    pdd unit;
    Line(pdd base, pdd other) : base(base) {
        pdd diff = make_pair(
            other._x - base._x,
            other._y - base._y
        );
        double len = norm(diff);
        unit = make_pair(
            diff._x / len,
            diff._y / len
        );
    }
};

double inner_prod(pdd p1, pdd p2) {
    return (p1._x * p2._x) + (p1._y * p2._y);
}

int main(void) {
    pdd p1, p2;
    cin >> p1._x >> p1._y;
    cin >> p2._x >> p2._y;

    Line lin(p1, p2);
    int qs;
    cin >> qs;
    for(int i = 0; i < qs; i++) {
        pdd p;
        cin >> p._x >> p._y;
        pdd inc = make_pair(
            p._x - lin.base._x,
            p._y - lin.base._y
        );
        double dist = inner_prod(inc, lin.unit);
        pdd vec = make_pair(
            lin.base._x + dist * lin.unit._x - p._x,
            lin.base._y + dist * lin.unit._y - p._y
        );
        pdd res = make_pair(
            p._x + vec._x * 2,
            p._y + vec._y * 2
        );
        printf("%.10lf %.10lf\n", res._x, res._y);
    }
    return 0;
}
