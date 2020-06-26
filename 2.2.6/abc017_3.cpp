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
#else
#define debug(fmt, ...)
#endif

#define INF (1e+9)
int main(void) {
    int num, types;
    cin >> num >> types;
    vector<int> point(types+1);
    int sum = 0;
    for(int i = 0; i < num; i++) {
        int start, end, p;
        cin >> start >> end >> p;
        start--; end--;
        point[start] += p;
        point[end+1] -= p;
        sum += p;
    }

    for(int i = 1; i <= types; i++) {
        point[i] += point[i-1];
    }

    int mmin = INF;
    for(int i = 0; i < types; i++) {
        debug("%d: %d\n", i, point[i]);
        mmin = min(mmin, point[i]);
    }
    cout << sum - mmin << endl;
    return 0;
}
