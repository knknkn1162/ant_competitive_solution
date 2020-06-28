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
#else
#define debug(fmt, ...)
#endif

int dfs(vector<vector<int>>& graph, map<pii, int>& colors, int node, int parent) {
    map<int, int> used;
    if(parent != -1) {
        int c = colors[make_pair(node, parent)];
        used[c] = 1;
    }
    int idx = 1;
    for(int elem: graph[node]) {
        if(elem == parent) continue;
        while(used[idx]) { idx++; }
        // paint
        colors[make_pair(elem, node)] = idx;
        colors[make_pair(node, elem)] = idx;
        used[idx++] = 1;
        dfs(graph, colors, elem, node);
    }
    return idx;
}

int main(void) {
    int vs;
    cin >> vs;
    vector<vector<int>> graph(vs);
    int es = vs-1;
    map<pii, int> colors;
    vector<pii> edges(es);
    vector<int> deg(vs);
    for(int i = 0; i < es; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        // 1-indexed -> 0-indexed
        v1--; v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        edges[i] = make_pair(v1, v2);
        deg[v1]++;
        deg[v2]++;
    }

    dfs(graph, colors, 0, -1);
    int k = *(max_element(deg.begin(), deg.end()));
    // presentation
    cout << k << endl;
    for(int i = 0; i < es; i++) {
        cout << colors[edges[i]] << endl;
    }
    return 0;
}
