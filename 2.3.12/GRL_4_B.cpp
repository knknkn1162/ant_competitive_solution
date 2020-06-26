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
#include <list>
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
#else
#define debug(fmt, ...)
#endif

static vector<bool> check;
void dfs(vector<vector<int>>& graph, int node, vector<int>& out) {
    check[node] = true;
    for(int elem: graph[node]) {
        if(check[elem]) continue;
        dfs(graph, elem, out);
    }
    out.push_back(node);
}

int main(void) {
    int vs, es;
    cin >> vs >> es;
    vector<vector<int>> graph(vs);
    check.resize(vs);
    fill(check.begin(), check.end(), false);
    for(int i = 0; i < es; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
    }

    vector<int> ans;
    for(int i = 0; i < vs; i++) {
        if(!check[i]) dfs(graph, i, ans);
    }

    reverse(ans.begin(), ans.end());
    for(int elem: ans) {
        cout << elem << endl;
    }
    return 0;
}
