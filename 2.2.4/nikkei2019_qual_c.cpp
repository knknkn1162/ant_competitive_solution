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
    vector<pii> arr(num);
    for(int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }
    auto comp = [](pii a, pii b) {
        return (a.first+a.second) > (b.first+b.second);
    };
    sort(arr.begin(), arr.end(), comp);

    vector<int64_t> points(num);
    for(int i = 0; i < num; i++) {
        if(i%2 == 0) {
            points[0] += arr[i].first;
        } else {
            points[1] += arr[i].second;
        }
    }

    cout << points[0] - points[1] << endl;
    return 0;
}
