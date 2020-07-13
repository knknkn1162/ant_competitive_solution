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
    return sqrt(p._x * p._x + p._y * p._y);
}

pdd get_unit_incline(pdd p1, pdd p2) {
    pdd diff = make_pair(
        p2._x - p1._x,
        p2._y - p1._y
    );
    double len = norm(diff);
    return make_pair(
        diff._x / len,
        diff._y / len
    );
}

#define INF 1000000
double outer_prod(pdd p1, pdd p2) {
    return p1._x * p2._y - p1._y * p2._x;
}
int main(void) {
    pdd p;
    cin >> p._x >> p._y;

    int num;
    cin >> num;
    vector<pdd> points(num*2);
    for(int i = 0; i < num; i++) {
        pdd tmp;
        cin >> tmp._x >> tmp._y;
        points[i] = tmp;
        points[i+num] = tmp;
    }

    pdd prev = points[0];
    double ans = INF;
    for(int i = 1; i < num*2; i++) {
        pdd cur = points[i];
        pdd base = prev;
        pdd target = make_pair(
            p._x - base._x,
            p._y - base._y
        );
        pdd unit = get_unit_incline(base, cur);
        double dist = abs(outer_prod(unit, target));
        debug("%lf, %lf -> %lf\n", unit._x, unit._y, dist);
        ans = min(dist, ans);
        prev = cur;
    }
    printf("%.7lf\n", ans);
    return 0;
}
