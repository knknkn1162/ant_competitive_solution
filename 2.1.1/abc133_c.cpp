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

#define DIV 2019
int main(void) {
    int left, right;
    cin >> left >> right;
    int left_ceil = ((left/DIV) + 1)*DIV;
    int right_floor = (right/DIV)*DIV;
    vector<int> map(DIV);
    for(int val = left; val <= left_ceil; val++) {
        if(val > right) break;
        map[val%DIV]++;
    }
    for(int val = max(left_ceil+1, right_floor); val <= right; val++) {
        if(val < left) continue;
        map[val%DIV]++;
    }

    int ans = DIV;
    for(int i = 0; i < DIV; i++) {
        if(!map[i]) continue;
        for(int j = 0; j < DIV; j++) {
            if(!map[j]) continue;
            if(i == j && map[j]<2) continue;
            ans = min(ans, (i*j)%DIV);
        }
    }
    cout << ans << endl;
    return 0;
}
