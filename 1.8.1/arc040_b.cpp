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


int main(void) {
    int num, rad;
    cin >> num >> rad;
    string str;
    cin >> str;
    int last = -1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '.') last = i;
    }
    if(last == -1) {
        cout << 0 << endl;
        return 0;
    }

    debug("last: %d\n", last);
    int ans = 0;
    int flag = 0;
    for(int i = 0; i < num; i++) {
        int idx = min(num, i+rad)-1;
        if(str[i] != 'o' || last <= idx) {
            ans++; // shoot
            for(int j = i; j <= idx; j++) {
                str[j] = 'o';
                if(j == last)  flag = 1;
            }
        }
        if(flag) break;
        ans++; // go forward
    }
    cout << ans << endl;
    return 0;
}
