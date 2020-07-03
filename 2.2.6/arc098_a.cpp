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


enum type {
    TYPE_WEST,
    TYPE_EAST,
    TYPE_ALL,
};

int main(void) {
    int num;
    cin >> num;
    string str;
    cin >> str;

    vector<char> table(256);
    table['W'] = TYPE_WEST; table['E'] = TYPE_EAST;

    vector<vector<int>> cum(num+2, vector<int>(2));
    vector<vector<int>> rcum(num+2, vector<int>(2));

    for(int i = 1; i <= num; i++) {
        char ch = table[str[i-1]];
        for(int k = 0; k < TYPE_ALL; k++) {
            cum[i+1][k] = cum[i][k] + (ch == k);
        }
    }

    for(int i = num; i >= 1; i--) {
        char ch = table[str[i-1]];
        for(int k = 0; k < TYPE_ALL; k++) {
            rcum[i-1][k] = rcum[i][k] + (ch == k);
        }
    }

    int ans = 0;
    for(int i = 1; i <= num; i++) {
        // [1, i), (i, num]
        debug("%d %d\n", cum[i][TYPE_EAST], rcum[i][TYPE_WEST]);
        // EEE*WWW
        ans = max(ans, cum[i][TYPE_EAST]+rcum[i][TYPE_WEST]);
    }
    cout << (num-1)-ans << endl;
    return 0;
}
