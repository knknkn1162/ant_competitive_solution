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
#include <cmath>
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

#define INF (1e+7)

int main(void) {
    int num;
    cin >> num;
    string str;
    cin >> str;

    vector<vector<int>> cum(num+1, vector<int>(2));

    for(int i = 1; i <= num; i++) {
        bool flag = (str[i-1] == '#');
        for(int k = 0; k < 2; k++) {
            cum[i][k] = cum[i-1][k] + (k == flag);
        }
    }

    int ans = 0;
    for(int pos = 0; pos <= num; pos++) {
        // make ...#####
        debug(".:%d #:%d\n", cum[pos][0],
            cum[num][1] - cum[pos][1]
        );
        ans = max(ans, cum[pos][0] + (cum[num][1] - cum[pos][1]));
    }
    cout << num-ans << endl;
    return 0;
}
