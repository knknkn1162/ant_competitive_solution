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
    vector<int> arr;
    for(int i = 0; i < num; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    vector<int> ans;
    while(!arr.empty()) {
        int flag = 0;
        for(int i = arr.size()-1; i >= 0; i--) {
            if(arr[i] == i+1) {
                arr.erase(arr.begin() + i);
                debug("%d\n", i+1);
                ans.push_back(i+1);
                flag = 1;
                break;
            }
        }
        if(!flag) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto e: ans) cout << e << endl;
    return 0;
}
