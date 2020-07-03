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

int get_area(pii p1, pii p2) {
    int diff1 = p1.second - p1.first;
    int diff2 = p2.second - p2.first;
    if(diff1 <= 0 || diff2 <= 0) return 0;
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
        switch(a) {
            case 1: // x < x_i
                range_x.first = max(range_x.first, x);
                break;
            case 2:
                range_x.second = min(range_x.second, x);
                break;
            case 3:
                range_y.first = max(range_y.first, y);
                break;
            case 4:
                range_y.second = min(range_y.second, y);
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
