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

using namespace std;

template<typename T>
void cins(vector<T> arr) { for(T e: arr) cin >> e; }

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T> arr) { for(T e: arr) p(e); }

void dfs(vector<vector<int>> mat, int node, vector<int>& out) {
    int res = 1;
    for(int child: mat[node]) {
        dfs(mat, child, out);
        res += out[child];
    }
    out[node] = res;
}

int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 1; i < num; i++) cin >> arr[i];
    vector<vector<int>> mat(num);
    for(int i = 1; i < num; i++) {
        int parent = arr[i];
        mat[parent].push_back(i);
    }
    vector<int> ans(num);
    dfs(mat, 0, ans);

    ps(ans);
    return 0;
}
