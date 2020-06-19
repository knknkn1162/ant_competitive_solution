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

bool within(pii p, int pos) {
    return p.first <= pos && pos <= p.second;
}

int main(void) {
    int num, days, tribes;
    cin >> num >> days >> tribes;
    vector<pii> ranges(days);
    for(pii& elem: ranges) {
        int start, end;
        cin >> start >> end;
        elem = make_pair(start, end);
    }

    vector<int> ans(tribes);
    for(int t = 0; t < tribes; t++) {
        int start, goal;
        cin >> start >> goal;
        debug("%d %d\n", start, goal);
        // D: 10000
        int cur = start;
        for(int d = 1; d <= days; d++) {
            pii elem = ranges[d-1];
            debug("%d, %d\n", t, cur);
            if(!within(elem, cur)) continue;
            if(within(elem, goal)) {
                ans[t] = d;
                break;
            }
            cur = (goal > cur) ? elem.second : elem.first;
        }
    }

    for(int elem: ans) {
        cout << elem << endl;
    }
    return 0;
}
