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


void uniq(vector<int>& arr, vector<int>& out) {
    int prev = arr[0] + 1;
    for(int i = 0; i < arr.size(); i++) {
        int cur = arr[i];
        if(prev == cur) continue;
        out.push_back(cur);
        prev = cur;
    }
}

int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);

    vector<int> arr2;
    uniq(arr, arr2);
    ps(arr2);
    if(arr2.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    int prev = arr[0];
    bool prev_plus = 1;
    // +, -, +, -
    vector<int> cnts;
    int points = 0;
    for(int i = 1; i < arr2.size(); i++) {
        int cur = arr2[i];
        bool cur_plus = (cur > prev);
        if(prev_plus != cur_plus) {
            cnts.push_back(points);
            points = 1;
        } else {
            points++;
        }
        prev = cur;
        prev_plus = cur_plus;
    }
    cnts.push_back(points);
    ps(cnts);

    int ans = 0;
    for(int i = 0; i < cnts.size(); i++) {
        if(cnts[i] == 0) continue;
        ans++;
    }
    cout << ((ans+1 >= 3) ? ans+1 : 0) << endl;

    return 0;
}
