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

int main(void) {
    int vs, es;
    cin >> vs >> es;
    set<int> vs1;
    set<int> vs2;
    for(int i = 0; i < es; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        if(v1 > v2) swap(v1, v2);
        if(v1 == 1) vs1.insert(v2);
        if(v2 == vs) vs2.insert(v1);
    }
    int sum = vs1.size() + vs2.size();
    for(int val: vs2) {
        vs1.insert(val);
    }
    int intersection = vs1.size();
    cout << (sum == intersection ? "IMPOSSIBLE" : "POSSIBLE") << endl;;
    return 0;
}
