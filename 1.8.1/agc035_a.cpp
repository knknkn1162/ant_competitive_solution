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

bool judge(map<int,int> &map, int num) {
    if(num%3) return false;
    int sz = num/3;
    vector<int> arr;
    for(pii p: map) {
        arr.push_back(p.first);
        if(p.second != sz) return false;
    }
    ps(arr);
    vector<int> idx = {0, 1, 2};
    int flag = true;
    do {
        flag &= ((arr[idx[0]] ^ arr[idx[1]]) == arr[idx[2]]);
    } while(next_permutation(idx.begin(), idx.end()));
    return flag;
}

// a1 ^ a2 = a3
// a2 ^ a3 = a2 ^ (a1 ^ a2) = a1
int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);
    map<int, int> map;
    for(int i = 0; i < num; i++) map[arr[i]]++;
    bool ans = 0;

    switch(map.size()) {
        case 1:
            // 0 ... 0
            if(map[0] == num) ans = true;
            break;
        case 2:
            // 0 3 3 0 3 3
            if(map[0]*3 == num) ans = true;
            break;
        case 3:
            if(num%3 == 0) ans = judge(map, num);
            break;
        default:
            break;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
