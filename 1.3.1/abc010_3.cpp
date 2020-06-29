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
#include <cmath>
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

#define EPS (1e-8)

double dist(pii p1, pii p2) {
    pii diff = {p2.first-p1.first, p2.second-p1.second};
    return sqrt(diff.first*diff.first + diff.second*diff.second);
}

int main(void) {
    pii start, end;
    int time;
    int v;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    cin >> time >> v;
    int num;
    cin >> num;
    int d = time * v;
    int flag = 0;
    for(int i = 0; i < num; i++) {
        pii p;
        cin >> p.first >> p.second;
        double mmin = dist(start, p) + dist(p, end);
        debug("compare %lf vs %d\n", mmin, d);
        if(mmin < d) {
            flag = 1;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
