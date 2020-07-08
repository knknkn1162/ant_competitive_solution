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
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

#define _x first
#define _y second
int main(void) {
    int num;
    cin >> num;
    vector<pii> points(num);
    for(int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    map<pii, vector<pii>> map;
    for(int i = 0; i < num; i++) {
        for(int j = i+1; j < num; j++) {
            pii p = make_pair(
                points[j]._x - points[i]._x,
                points[j]._y - points[i]._y
            );
            pii pinv = make_pair(-p._x, -p._y);
            map[p].push_back(make_pair(i, j));
            map[pinv].push_back(make_pair(i, j));
        }
    }

    int mmax = 0;
    for(auto pair: map) {
        debug("[%d, %d] -> %ld\n", pair.first._x, pair.first._y, pair.second.size());
        // pair.second.size(): edges
        mmax = max((int)pair.second.size(), mmax);
    }
    cout << num-mmax << endl;
    return 0;
}
