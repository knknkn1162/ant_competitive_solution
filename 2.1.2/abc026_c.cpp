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

int calc_salary_dfs(vector<vector<int>>& tree, int me) {
    vector<int> cands;
    for(int elem: tree[me]) {
        cands.push_back(calc_salary_dfs(tree, elem));
    }
    if(cands.empty()) {
        return 1;
    } else {
        int mmin = *min_element(cands.begin(), cands.end());
        int mmax = *max_element(cands.begin(), cands.end());
        return mmin + mmax + 1;
    }
}

int main(void) {
    int num;
    cin >> num;
    vector<vector<int>> tree(num+1);
    for(int i = 0; i < num-1; i++) {
        int tthis = i+2;
        int parent;
        cin >> parent;
        tree[parent].push_back(tthis);
    }

    int ans = calc_salary_dfs(tree, 1);
    cout << ans << endl;
    return 0;
}
