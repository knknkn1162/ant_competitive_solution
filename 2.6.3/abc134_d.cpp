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
#include <math.h>
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
    vector<int> arr(num+1);
    for(int i = 1; i <= num; i++) {
        int val;
        cin >> val;
        arr[i] = val;
    }

    vector<int> ans(num+1);
    for(int i = num; i >= 1; i--) {
        int mmax = sqrt(0.5+i);
        debug("%d -> %d-%d\n", i, ans[i], arr[i]);
        int cur = abs(ans[i] - arr[i]);
        ans[i] = cur;
        if(i == 1) break;
        for(int div = 1; div <= mmax; div++) {
            if(i%div) continue;
            ans[div] = (ans[div] + cur)%2;
            if(div*div==i) continue;
            if(div>1) ans[i/div] = (ans[i/div] + cur)%2;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= num; i++) {
        cnt += ans[i];
    }

    cout << cnt << endl;
    for(int i = 1; i <= num; i++) {
        if(!ans[i]) continue;
        cnt--;
        cout << i;
        cout << ((cnt==0) ? '\n' : ' ');
    }
    return 0;
}
