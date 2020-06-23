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
    string str, sub;
    cin >> str;
    cin >> sub;
    vector<vector<int>> pos(26);
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i] - 'a';
        pos[ch].push_back(i);
        pos[ch].push_back(i+str.size());
    }

    for(int i = 0; i < 26; i++) {
        sort(pos[i].begin(), pos[i].end());
    }

    int round = 0;
    int idx = -1;
    for(int i = 0; i < sub.size(); i++) {
        char ch = sub[i] - 'a';
        debug("%c: size: %d\n", sub[i], pos[ch].size());
        if(pos[ch].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        // greater than or equal to pos
        auto nidx = upper_bound(pos[ch].begin(), pos[ch].end(), idx);
        idx = *(nidx);
        if(idx >= str.size()) {
            idx -= str.size();
            round++;
        }
    }
    int64_t ans = ((int64_t)round*str.size()) + idx;
    // 1-indexed
    ans++;
    cout << ans << endl;
    return 0;
}
