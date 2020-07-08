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

int64_t calc_diff(vector<int>& arr) {
    vector<int> cand;
    int size = arr.size();
    for(int i = 0; i <= size/2; i++) {
        cand.push_back(arr[i]);
        if(i == size-1-i) continue;
        cand.push_back(arr[size-1-i]);
    }
    ps(cand);

    int64_t sum = 0;
    int prev = arr[0];
    for(int i = 1; i < size-1; i++) {
        int cur = cand[i];
        sum += abs(cur - prev);
        prev = cur;
    }
    int last = cand[size-1];
    sum += max(abs(last-cand[size-2]), abs(last-cand[0]));
    return sum;
}

int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);
    sort(arr.begin(), arr.end());
    int64_t sum = calc_diff(arr);
    reverse(arr.begin(), arr.end());
    sum = max(sum, calc_diff(arr));

    cout << sum << endl;
    return 0;
}
