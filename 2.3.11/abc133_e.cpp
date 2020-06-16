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

#define DIVISOR 1000000007
pii gcdext(int a, int b) {
    if(a==0) { return make_pair(0,1); }
    pii p = gcdext(b%a, a);
    return make_pair(p.second - (b/a)*p.first, p.first);
}

static vector<int64_t> factorial;
static vector<int64_t> inv_factorial;

void init_factorial(int size) {
    factorial.resize(size+1);
    inv_factorial.resize(size+1);
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;

    for(int i = 2; i <= size; i++) {
        factorial[i] = (factorial[i-1] * i)%DIVISOR;
        pii p = gcdext(i, DIVISOR);
        int inv = (p.first + DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1] * inv)%DIVISOR;
    }
    return;
}

int64_t calc_npk(int n, int k) {
    if(k > n) return 0;
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    // ans = (ans * inv_factorial[k])%DIVISOR;
    debug("%d, %d -> %lld\n", n, k, ans);
    return ans;
}

int64_t calc_nck(int n, int k) {
    if(k > n) return 0;
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    debug("%d, %d -> %lld\n", n, k, ans);
    return ans;
}


int64_t dfs(vector<vector<int>>& graph, int k, int node, int parent) {
    int64_t ans = (parent==-1) ? k : 1;
    int cnt = 0;
    for(int elem: graph[node]) {
        if(elem==parent) continue;
        //excluding parent
        ans = (ans * dfs(graph, k, elem, node))%DIVISOR;
        cnt++;
    }
    int is_parent = (parent!=-1); // exclude parent node
    ans = (ans * calc_npk(k-1-is_parent, cnt))%DIVISOR;
    return ans;
}

int main(void) {
    int vs, k;
    cin >> vs >> k;
    int es = vs-1;
    vector<vector<int>> graph(vs);
    init_factorial(max(vs, k));
    for(int i = 0; i < es; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        // 1-indexed -> 0-indexed
        v1--; v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int64_t ans = dfs(graph, k, 0, -1);
    cout << ans << endl;
    return 0;
}
