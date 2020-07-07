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


int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    vector<int> brr(num);
    cins(arr);
    cins(brr);

    int64_t as = 0;
    int64_t bs = 0;
    for(int i = 0; i < num; i++) {
        if(arr[i] < brr[i]) {
            bs += (brr[i] - arr[i])/2;
        } else {
            as += (arr[i] - brr[i]);
        }
    }
    debug("%ld <- %ld\n", bs, as);
    cout << (bs - as >= 0 ? "Yes" : "No") << endl;
    return 0;
}
