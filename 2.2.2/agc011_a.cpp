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


#define INF (1e+9)
int main(void) {
    int num, cap, limit;
    cin >> num >> cap >> limit;
    vector<pii> ranges(num);
    for(int i = 0; i < num; i++) {
        int time;
        cin >> time;
        ranges[i] = make_pair(time, time+limit+1);
    }
    auto comp = [](pii a, pii b) {
        return a.second < b.second;
    };
    sort(ranges.begin(), ranges.end(), comp);

    int ans = 0;
    int time = 0;
    int ps = 0;
    for(int i = 0; i < num; i++) {
        pii r = ranges[i];
        if(ps == cap) {
            time = 0;
        }
        if(r.first < time) {
            ps++;
        // too early for r
        } else {
            ans++;
            time = r.second;
            ps = 1;
        }
        debug("[time: %d] %d\n", time, ans);
    }
    cout << ans << endl;
    return 0;
}
