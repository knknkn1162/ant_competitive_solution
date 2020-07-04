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
#define DIVISOR 998244353

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


int main(void) {
    int vs;
    cin >> vs;
    vector<int> map(vs+1);
    bool flag = 1;
    for(int i = 0; i < vs; i++) {
        int dist;
        cin >> dist;
        // impossible!
        if(i == 0 && dist != 0) flag = 0;
        if(i != 0 && dist == 0) flag = 0;
        map[dist]++;
    }

    ps(map);
    vector<int> powers(vs+1);
    int cnt = map[0];
    for(int i = 1; i <= vs; i++) {
        int base = map[i-1];
        int power = map[i];
        cnt += power;
        if(power == 0) break;
        powers[base] += power;
    }
    debug("%d\n", cnt);
    // This is not connected
    if(cnt != vs) flag = 0;

    int64_t ans = 1;
    for(int base = 1; base <= vs; base++) {
        debug("%d -> %d -> %ld\n", base, powers[base], ans);
        while(powers[base]--) {
            ans = (ans * base)%DIVISOR;
        }
    }
    cout << (flag ? ans : 0) << endl;
    return 0;
}
