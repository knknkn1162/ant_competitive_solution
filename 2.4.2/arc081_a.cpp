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

int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);
    map<int, int> map;
    vector<int> cands;
    cands.push_back(0);
    cands.push_back(0);
    for(int i = 0; i < num; i++) {
        map[arr[i]]++;
        if(map[arr[i]] == 2) {
            cands.push_back(arr[i]);
            map[arr[i]] = 0;
        }
    }
    sort(cands.begin(), cands.end(), greater<int>());

    int64_t ans = (int64_t)cands[0] * cands[1];
    cout << ans << endl;

    return 0;
}
