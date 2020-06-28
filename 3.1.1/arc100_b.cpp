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
#define debugs(fmt, ...)
#endif

#define INF (1e+15)

int64_t calc_diff(pII left, pII right) {
    vector<int64_t> elem = { left.first, left.second, right.first, right.second };
    // for(auto e: elem) 
    // cout << endl;
    int64_t mmin = *min_element(elem.begin(), elem.end());
    int64_t mmax = *max_element(elem.begin(), elem.end());
    return mmax - mmin;
}

int main(void) {
    int num;
    cin >> num;
    vector<int64_t> cum(num+1);
    for(int i = 1; i <= num; i++) {
        cin >> cum[i];
        cum[i] += cum[i-1];
    }
    int64_t ans = INF;
    for(int i = 2; i < num-1; i++) {
        // first [0, i) second: [i, num)
        int64_t sum1 = cum[i];
        int64_t sum2 = cum[num] - sum1;
        auto pos1 = lower_bound(cum.begin(), cum.begin()+i, sum1/2);
        auto pos2 = lower_bound(cum.begin()+i, cum.end(), sum2/2+sum1);
        // [0, pos1] [pos1+1, i]
        int64_t p1 = *(pos1-1); int64_t q1 = sum1-p1;
        int64_t p2 = *(pos1); int64_t q2 = sum1-p2;
        pII left_cands[2] = {
            {p1, q1},
            {p2, q2},
        };
        int64_t r1 = *(pos2-1) - sum1; int64_t s1 = sum2 - r1;
        int64_t r2 = *(pos2) - sum1; int64_t s2 = sum2 - r2;
        pII right_cands[2] = {
            {r1, s1},
            {r2, s2},
        };

        for(pII left: left_cands) {
            for(pII right: right_cands) {
                ans = min(ans, calc_diff(left, right));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
