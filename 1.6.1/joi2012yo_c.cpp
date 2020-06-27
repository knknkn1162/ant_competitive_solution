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
#define debug(fmt, ...)
#endif

int main(void) {
    int num;
    cin >> num;
    int cost;
    int topping_cost;
    cin >> cost >> topping_cost;
    int cals;
    cin >> cals;
    vector<int> arr(num);
    cins(arr);
    sort(arr.begin(), arr.end(), greater<int>());

    double ans = (double)cals / cost;
    debug("init: %lf\n", ans);
    for(int i = 0; i < num; i++) {
        cals += arr[i];
        cost += topping_cost;
        double res = (double)cals / cost;
        debug("%d: %lf\n", i, res);
        ans = max(ans, res);
    }
    cout << (int)ans << endl;
    return 0;
}
