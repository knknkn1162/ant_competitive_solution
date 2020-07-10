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

int get_dist(pii p1, pii p2) {
    int diff_x = p2.first - p1.first;
    int diff_y = p2.second - p1.second;
    return diff_x * diff_x + diff_y * diff_y;
}

int main(void) {
    int num;
    cin >> num;
    vector<pii> arr(num);
    for(int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }

    int max2 = 0;
    for(int i = 0; i < num; i++) {
        for(int j = i+1; j < num; j++) {
            max2 = max(max2, get_dist(arr[i], arr[j]));
        }
    }

    printf("%.4lf\n", sqrt(max2));

    return 0;
}
