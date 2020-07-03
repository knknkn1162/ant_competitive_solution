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

int power10(int num) {
    if(num == 0) return 0;
    int ans = 1;
    while(num--) {
        ans *= 10;
    }
    return ans;
}

int main(void) {
    int num, qs;
    cin >> num >> qs;
    vector<pii> queries(qs);
    for(int i = 0; i < qs; i++) {
        int s, c;
        cin >> s >> c;
        queries[i] = make_pair(s, c);
    }
    int ans = -1;
    for(int n = power10(num-1); n < power10(num); n++) {
        int flag = 1;
        for(int k = 0; k < qs; k++) {
            int val = n;
            pii q = queries[k];
            int s = num+1-q.first; // power10(s)
            while(--s) {
                val /= 10;
            }
            val %= 10;
            if(val != q.second) { flag = 0; break; }
        }
        if(flag) { ans = n; break; }
    }
    cout << ans << endl;
    return 0;
}
