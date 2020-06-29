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

#define UNIT 400
#define ULIMIT 3200
#define COLORS_MAX 8
int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);
    vector<int> map(COLORS_MAX+1);
    for(int i = 0; i < num; i++) {
        int color = min(arr[i], ULIMIT)/UNIT;
        map[color]++;
    }

    int ans = 0;
    for(int i = 0; i < COLORS_MAX; i++) {
        ans += (map[i]>0);
    }
    cout << max(1, ans) << " ";
    cout << ans+map[COLORS_MAX] << endl;
    return 0;
}
