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


#define INF 10000

int main(void) {
    int num; int llimit;
    cin >> num >> llimit;
    vector<pii> arr(num+1); // arr[num] ... for guard
    for(int i = 0; i < num; i++) {
        int count, bonus;
        cin >> count >> bonus;
        arr[i] = make_pair(count, bonus);
    }

    int ans = INF;
    for(int pat = 0; pat < (1<<num); pat++) {
        int sum = 0;
        int count = 0;
        int partial = num;
        // get bonus
        for(int bit = 0; bit < num; bit++) {
            if(!(pat & (1<<bit))) {
                partial = bit; continue;
            }
            int point = (bit+1)*100;
            pii p = arr[bit];
            sum += (p.first*point + p.second);
            count += p.first;
        }
        // get highest score partially
        pii p = arr[partial];
        int point = (partial+1)*100;
        int rem = llimit-sum;
        int cnt = 0;
        if(rem>=1) cnt = (rem-1)/point + 1;
        cnt = min(cnt, p.first);
        count += cnt;
        sum += point*cnt;
        debug("cnt: %d(partial: %d) -> %d\n", count, partial, sum);
        if(sum >= llimit) ans = min(ans, count);
    }

    cout << ans << endl;
    return 0;
}
