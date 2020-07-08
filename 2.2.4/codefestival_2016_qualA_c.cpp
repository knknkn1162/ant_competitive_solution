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


#define SIZE 26
int main(void) {
    string str;
    int k;
    cin >> str;
    int len = str.length();
    cin >> k;
    string ans;
    for(char ch: str) {
        int next_a = (SIZE - (ch - 'a'))%SIZE;
        if(next_a <= k) {
            k -= next_a;
            ch = 'a';
        }
        ans.push_back(ch);
    }
    debug("k: %d -> %s\n", k, ans.c_str());

    if(k > 0) {
        char last = ans[len-1] - 'a';
        ans[len-1] = (last + k)%SIZE + 'a';
    }

    cout << ans << endl;
    return 0;
}
