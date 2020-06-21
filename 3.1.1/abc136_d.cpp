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
    string str;
    cin >> str;
    int len = str.length();
    vector<int> lefts;
    vector<int> rights;
    for(int i = 0; i < len; i++) {
        if(str[i] == 'L') {
            lefts.push_back(i);
        } else if(str[i] == 'R') {
            rights.push_back(i);
        }
    }

    vector<int> map(len);
    for(int i = 0; i < len; i++) {
        int res = 0;
        if(str[i] == 'L') {
            auto pos = lower_bound(rights.begin(), rights.end(), i);
            // maximum
            res = *(pos-1);
            if(abs(i-res)%2) res++;
            map[res]++;
        } else {
            // minimum
            auto pos = lower_bound(lefts.begin(), lefts.end(), i);
            res = *pos;
            if(abs(i-res)%2) res--;
            map[res]++;
        }
        debug("%d -> %d\n", i, res);
    }
    for(int i = 0; i < len; i++) {
        cout << map[i];
        cout << ((i == len-1) ? '\n' : ' ');
    }
    return 0;
}
