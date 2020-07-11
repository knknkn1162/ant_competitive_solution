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

enum type {
    TYPE_CCW,
    TYPE_CW,
    TYPE_ONBACK,
    TYPE_ONFRONT,
    TYPE_ONSEG,
};

string table[] = {
    "COUNTER_CLOCKWISE",
    "CLOCKWISE",
    "ONLINE_BACK",
    "ONLINE_FRONT",
    "ON_SEGMENT",
};

#define EPS (1e-6)
double outer_prod(pdd p1, pdd p2) {
    return p1._x * p2._y - p2._x * p1._y;
}

double norm(pdd p1) {
    return sqrt(p1._x*p1._x + p1._y*p1._y);
}

pdd get_incline(pdd p1, pdd p2, double* len) {
    pdd inc = make_pair(
        p2._x - p1._x,
        p2._y - p1._y
    );
    double leng = norm(inc);
    *len = leng;
    return make_pair(
        inc._x / leng,
        inc._y / leng
    );
}

bool is_equal(pdd p1, pdd p2) {
    return abs(p1._x - p2._x) < EPS && abs(p1._y - p2._y) < EPS;
}

int main(void) {
    pdd base, p2;
    cin >> base._x >> base._y;
    cin >> p2._x >> p2._y;
    double len1;
    pdd inc = get_incline(base, p2, &len1);
    int qs;
    cin >> qs;
    for(int i = 0; i < qs; i++) {
        pdd p;
        cin >> p._x >> p._y;
        double len2;
        pdd diff = get_incline(base, p, &len2);
        debug("%lf\n", len2);
        double val = outer_prod(inc, diff);
        int type;
        if(val > EPS) {
            type = TYPE_CCW;
        } else if(val < -EPS) {
            type = TYPE_CW;
        } else {
            // abs(val) < EPS
            if(abs(inc._x + diff._x) < EPS && \
                abs(inc._y + diff._y) < EPS) {
                type = TYPE_ONBACK;
            } else {
                if(is_equal(p2, p)) {
                    type = TYPE_ONSEG;
                } else {
                    type = (len1 > len2) ? TYPE_ONSEG : TYPE_ONFRONT;
                }
            }
        }
        cout << table[type] << endl;
    }
    return 0;
}
