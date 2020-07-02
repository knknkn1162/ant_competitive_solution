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


int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    vector<int> map(26);
    for(int i = 0; i < len; i++) {
        map[str[i]-'a']++;
    }
    char next = -1;
    for(int i = 0; i < 26; i++) {
        if(!map[i]) {
            next = i;
            break;
        }
    }
    if(next>-1) {
        cout << str << (char)(next + 'a') << endl;
        return 0;
    }
    vector<int> arr(len);
    vector<int> old(len);
    for(int i = 0; i < len; i++) {
        arr[i] = str[i]-'a';
        old[i] = arr[i];
    }
    if(!next_permutation(arr.begin(), arr.end())) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < len; i++) {
            putchar(arr[i]+'a');
            if(arr[i] != old[i]) break;
        }
        putchar('\n');
    }
    return 0;
}
