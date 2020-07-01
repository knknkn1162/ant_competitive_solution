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

enum type {
    TYPE_UP,
    TYPE_DOWN,
};

char table[2] = {
    'U',
    'D'
};

int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    // assume that S_1: 'U', S_len: 'D'
    int64_t sum = (len-1)*2;
    for(int i = 1; i < len-1; i++) {
        int ups = len-i-1;
        int downs = i;
        if(str[i] == 'U') {
            // (i, len-1]
            sum += ups + downs*2;
        } else {
            sum += ups*2 + downs;
        }
    }
    cout << sum << endl;
    return 0;
}
