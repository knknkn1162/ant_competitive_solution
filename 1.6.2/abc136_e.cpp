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
#include <cmath>
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
    int num, k;
    cin >> num >> k;
    vector<int> arr(num);
    cins(arr);
    int sum = 0;
    for(int elem: arr) {
        sum += elem;
    }
    int sum_2 = sqrt(0.5+sum);
    vector<int> divs;
    for(int i = 1; i <= sum_2; i++) {
        if(sum%i) continue;
        divs.push_back(i);
        if(i*i==sum) continue;
        divs.push_back(sum/i);
    }
    sort(divs.begin(), divs.end(), greater<int>());

    vector<int> diffs(arr.size());
    int ans = 0;
    for(int div: divs) {
        int64_t sum_diff = 0;
        for(int i = 0; i < arr.size(); i++) {
            diffs[i] = arr[i]%div;
            sum_diff += diffs[i];
        }

        sort(diffs.begin(), diffs.end(), greater<int>());
        int64_t sum_upper = 0;
        for(int i = 0; i < diffs.size(); i++) {
            if(sum_diff <= k) break;
            sum_diff -= diffs[i];
            sum_upper += (div-diffs[i]);
        }
        if(sum_diff <= k && sum_upper <= k) {
            ans = div;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
