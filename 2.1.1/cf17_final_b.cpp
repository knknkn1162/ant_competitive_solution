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
    debug("[debug: %s] ", __func__); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

int find(vector<int> arr, int val) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    bool flag = 0;
    vector<int> map(3);
    if(len == 1) {
        flag = 1;
        goto finish;
    }
    for(int i = 0; i < str.length(); i++) {
        map[str[i]-'a']++;
    }


    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // "aa"
            if(i == j) continue;
            int pprev = i;
            int prev = j;
            vector<int> abc_map(3);
            vector<int> mmap(map);
            if(!mmap[i] || !mmap[j]) continue;
            abc_map[pprev]++;
            abc_map[prev]++;
            mmap[pprev]--;
            mmap[prev]--;
            bool is_ok = 1;
            for(int k = 2; k < len; k++) {
                int cur = find(abc_map, 0);
                if(!mmap[cur]) { is_ok = 0; break; }
                // update
                abc_map[pprev]--;
                abc_map[cur]++;
                mmap[cur]--;
                pprev = prev;
                prev = cur;
            }
            debug("%c%c -> %d\n", i+'a', j+'a', is_ok);
            if(is_ok) {
                flag = 1;
                goto finish;
            }
        }
    }

finish:
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
