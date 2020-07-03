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

bool is_contain(pii p1, pii p2) {
    return p1.first <= p2.first && p2.second <= p1.second;
}
bool is_overlap(pii p1, pii p2) {
    return p1.first <= p2.second && p2.first <= p1.second;
}
pii intersect(pii p1, pii p2) {
    if(is_contain(p1, p2)) { // p2 \in p1
        return p2;
    } else if (is_contain(p2, p1)) {
        return p1;
    } else if(is_overlap(p1, p2)) {
        int v1 = p1.second - p2.first;
        int v2 = p2.second - p1.first;
        if(v1 >= v2) {
            return make_pair(p1.first, p2.second);
        } else {
            return make_pair(p2.first, p1.second);
        }
    }
    return make_pair(0, 0);
}

int get_area(pii p1, pii p2) {
    int diff1 = p1.second - p1.first;
    int diff2 = p2.second - p2.first;
    return diff2*diff1;
}

int main(void) {
    int width, height, qs;
    cin >> width >> height >> qs;
    pii range_x = make_pair(0, width);
    pii range_y = make_pair(0, height);
    for(int i = 0; i < qs; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        pii white;
        switch(a) {
            case 1: // x < x_i
                white = make_pair(x, width);
                range_x = intersect(range_x, white);
                break;
            case 2:
                white = make_pair(0, x);
                range_x = intersect(range_x, white);
                break;
            case 3:
                white = make_pair(y, height);
                range_y = intersect(range_y, white);
                break;
            case 4:
                white = make_pair(0, y);
                range_y = intersect(range_y, white);
                break;
            default:
                break;
        }
        debug("x: %d, %d ", range_x.first, range_x.second);
        debug("y: %d, %d\n ", range_y.first, range_y.second);
    }
    cout << get_area(range_x, range_y) << endl;
    return 0;
}
