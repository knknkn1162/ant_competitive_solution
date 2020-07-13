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


int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);
    if(num == 1) {
        cout << 1 << endl;
        return 0;
    }

    int seq = 0;
    // plus
    int prev_sgn = 0;
    vector<int> cnts;
    for(int i = 1; i < num; i++) {
        int diff = arr[i] - arr[i-1];
        int cur_sgn = (diff<0);
        if(cur_sgn == prev_sgn) {
            seq++;
        } else {
            cnts.push_back(seq);
            seq = 1;

        }
        debug("%d-%d : %d\n", i-1, i,seq);
        prev_sgn = cur_sgn;
    }
    cnts.push_back(seq);
    cnts.push_back(0);

    int ans = 0;
    for(int i = 0; i < cnts.size(); i+=2) {
        ans = max(ans, cnts[i] + cnts[i+1]);
    }

    cout << ans+1 << endl;
    return 0;
}
