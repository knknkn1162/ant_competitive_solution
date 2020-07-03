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
#define _y second;

int diff(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(void) {
    int num;
    cin >> num;
    int tcur = 0;
    pii curp = make_pair(0, 0);
    bool flag = true;
    for(int i = 0; i < num; i++) {
        pii nextp;
        int tnext;
        cin >> tnext >> nextp._x >> nextp._y;
        int dist = diff(curp, nextp);
        debug("time: %d -> dist: %d\n", tnext-tcur, dist);
        if(tnext - tcur < dist) flag = false;
        if(((tnext - tcur)-dist)%2 == 1) flag = false;
        curp = nextp;
        tcur = tnext;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
