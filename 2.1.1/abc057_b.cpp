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
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif
#define INF (1e+9)

#define _x first
#define _y second

int manh(pii p1, pii p2) {
    return abs(p1._x-p2._x) + abs(p1._y-p2._y);
}
int main(void) {
    int num, ps;
    cin >> num >> ps;
    vector<pii> arr(num);
    for(int i = 0; i < num; i++) {
        int x,y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }
    vector<pii> points(ps);
    for(int i = 0; i < ps; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x,y);
    }

    for(int i = 0; i < num; i++) {
        pii person = arr[i];
        int mmin = INF;
        int argmin = 0;
        for(int j = 1; j <= ps; j++) {
            int nnew = manh(person, points[j-1]);
            if(mmin > nnew) {
                mmin = min(mmin, nnew);
                argmin = j;
            }
        }
        cout << argmin << endl;
    }
    return 0;
}
