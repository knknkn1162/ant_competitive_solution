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
typedef pair<double, double> pdd;
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
    vector<int> table = {
        31, 29, 31,
        30, 31, 30,
        31, 31, 30,
        31, 30, 31
    };
    int num;
    cin >> num;
    vector<int> days(368);
    for(int i = 1; i <= 366; i++) {
        int mod = i%7;
        // Sunday or Saturday
        days[i] = (mod == 1 || mod == 0);
    }
    days[367] = 0; // for guard
    
    for(int i = 0; i < num; i++) {
        int m, d;
        scanf("%d/%d", &m, &d);
        int idx = 0;
        for(int i = 0; i < m-1; i++) {
            idx += table[i];
        }
        idx += d;
        debug("%d\n", idx);
        days[idx]++;
    }

    int bonus = 0;
    for(int i = 1; i <= 366; i++) {
        if(days[i] >= 1) {
            bonus += (days[i]-1);
            days[i] = 1;
        } else {
            if(bonus) { days[i]++; bonus--; }
        }
    }

    int cnt = 0;
    int ans = 2;
    for(int i = 1; i <= 367; i++) {
        if(days[i] == 1) {
            cnt++;
        } else {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }

    cout << ans << endl;
    return 0;
}
