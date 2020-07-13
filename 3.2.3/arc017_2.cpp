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
    int num, k;
    cin >> num >> k;
    vector<int> arr(num);
    cins(arr);
    if(k == 1) {
        cout << arr.size() << endl;
        return 0;
    }

    int prev = arr[0];
    bool prev_plus = true;
    int cnt = 0;
    vector<int> rle;
    for(int i = 1; i < num; i++) {
        int cur = arr[i];
        bool cur_plus = (cur>prev);
        if(prev_plus == cur_plus) {
            cnt++;
        } else {
            rle.push_back(cnt+1);
            cnt = 1;
        }
        prev = cur;
        prev_plus = cur_plus;
    }
    rle.push_back(cnt+1);
    ps(rle);

    int ans = 0;
    for(int i = 0; i < rle.size(); i+=2) {
        ans += max(rle[i]-k+1, 0);
    }
    cout << ans << endl;
    return 0;
}
