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


#define NUM_MAX 3500
int main(void) {
    int64_t num;
    cin >> num;

    vector<int> ans(3);
    for(int64_t k1 = 1; k1 <= NUM_MAX; k1++) {
        for(int64_t k2 = 1; k2 <= NUM_MAX; k2++) {
            int64_t nume = (int64_t)num * k1 * k2;
            int64_t deno = 4*k1*k2 - num*k1 - num*k2;
            if(deno <= 0) continue;
            if(nume%deno) continue;
            int64_t k3 = nume/deno;
            ans[0] = k1; ans[1] = k2; ans[2] = k3;
            break;
        }
    }

    for(auto e: ans) cout << e << " ";
    cout << endl;
    return 0;
}
