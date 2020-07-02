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

int64_t gcd(int64_t val1, int64_t val2) {
    if(val1 == 0) return val2;
    return gcd(val2%val1, val1);
}
int64_t lcm(int64_t val1, int64_t val2) {
    if(val1 > val2) swap(val1, val2);
    return val1 / gcd(val1, val2) * val2;
}

int main(void) {
    int snum, tnum;
    cin >> snum >> tnum;
    vector<string> str(2);
    cin >> str[0];
    cin >> str[1];
    int64_t len = lcm(snum, tnum);

    bool flag = 1;
    map<int64_t, char> map;

    // judge existance
    for(int k = 0; k < 2; k++) {
        int unit = len/str[k].length();
        debug("%d\n", unit);
        for(int64_t i = 0; i < len; i+=unit) {
            int idx = (int)(i/unit);
            if(map[i] && map[i] != str[k][idx]) {
                flag = 0;
                break;
            }
            map[i] = str[k][idx];
        }
    }
    cout << (flag ? len : -1) << endl;
    return 0;
}
