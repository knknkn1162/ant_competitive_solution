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

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T>& arr) { for(T e: arr) p(e); }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

int main(void) {
    int num;
    cin >> num;
    int64_t sum = 0;
    int64_t sum_0 = 0;
    vector<int> arr(num);
    for(int i = 0; i < num; i++) {
        int val;
        cin >> val;
        arr[i] = val;
        sum += val;
        if(i%2==1) sum_0 += val;
    }
    sum /= 2;
    vector<int64_t> ans(num);
    ans[0] = sum - sum_0;
    int64_t cur = ans[0];
    for(int i = 0; i < num-1; i++) {
        ans[i+1] = arr[i] - cur;
        cur = ans[i+1];
    }

    for(int i = 0; i < num; i++) {
        cout << ans[i] * 2;
        cout << ((i == num-1) ? '\n' : ' ');
    }
    return 0;
}
