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

bool judge(vector<int>& arr, int64_t key, int goal) {
    int64_t sum_diff = 0;
    static vector<int64_t> diffs(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        int64_t diff = arr[i]%key;
        diffs[i] = min(diff, key-diff);
        sum_diff += diffs[i];
    }
    // desc
    sort(diffs.begin(), diffs.end(), greater<int64_t>());
    int64_t sum_upper = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(sum_diff <= goal) break;
        sum_diff -= diffs[i];
        sum_upper += (key-diffs[i]);
    }
    debug("key: %d(goal: %d) -> %lld %lld\n", key, goal,
        sum_diff, sum_upper);
    return sum_diff <=goal && sum_upper <= goal;
}

int main(void) {
    int num, k;
    cin >> num >> k;
    vector<int> arr(num);
    cins(arr);
    int sum = 0;
    for(int elem: arr) {
        sum += elem;
    }

    int64_t high = sum+1;
    int64_t low = 0;
    while(low + 1 < high) {
        int64_t mid = (low + high)/2;
        if(judge(arr, mid, k)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    debug("tmp: %d\n", low);
    int64_t sum_2 = sqrt(0.5+sum);
    vector<int> divs;
    for(int i = 1; i <= sum_2; i++) {
        if(sum%i) continue;
        divs.push_back(i);
        if(i*i==sum) continue;
        divs.push_back(sum/i);
    }
    sort(divs.begin(), divs.end());
    auto it = upper_bound(divs.begin(), divs.end(), low);
    cout << *(it-1) << endl;
    return 0;
}
