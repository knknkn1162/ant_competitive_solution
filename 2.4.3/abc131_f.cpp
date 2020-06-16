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
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T>& arr) { for(T e: arr) p(e); }

struct node {
    int parent;
    int depth;
};

class Ufind {
private:
    vector<struct node> nodes;
public:
    Ufind(int size) : nodes(size) {
        for(int i = 0; i < size; i++) {
            nodes[i].parent = i;
            nodes[i].depth = 0;
        }
    }

    int find_root(int v) {
        struct node *elem = &nodes[v];
        int base = v;
        if(base == elem->parent) {
            return base;
        } else {
            int root = find_root(elem->parent);
            elem->parent = root;
            return root;
        }
    }

    int is_connect(int v1, int v2) {
        return find_root(v1) == find_root(v2);
    }

    void unite(int v1, int v2) {
        int bv1 = find_root(v1);
        int bv2 = find_root(v2);
        struct node *uv1 = &nodes[bv1];
        struct node *uv2 = &nodes[bv2];
        if(uv1->depth >= uv2->depth) {
            if(uv1->depth == uv2->depth) uv1->depth++;
            uv2->depth = uv1->depth;
            uv2->parent = uv1->parent;
        } else {
            uv1->depth = uv2->depth;
            uv1->parent = uv2->parent;
        }
        return;
    }
};

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug] " fmt, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

typedef pair<int,int> pii;
#define POS_MAX 100000

int main(void) {
    int num;
    cin >> num;
    int size = POS_MAX*2+2;
    Ufind ufind(size);
    vector<pii> ps(num);
    for(int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        // 1-indexed
        int v1 = x*2; int v2 = y*2+1;
        ps[i] = make_pair(v1, v2);
        if(!ufind.is_connect(v1, v2)) {
            ufind.unite(v1, v2);
        }
    }
    // default: 0
    vector<int> roots(size);
    map<int, int> edges;
    for(pii p: ps) {
        int v = ufind.find_root(p.first);
        roots[p.first] = v;
        roots[p.second] = v;
        edges[v]++;
    }
    vector<int> map_x(size);
    vector<int> map_y(size);
    for(int i = 2; i < size; i++) {
        if(i%2==0) map_x[roots[i]]++;
        if(i%2==1) map_y[roots[i]]++;
    }
    int64_t ans = 0;
    for(pii e: edges) {
        int root = e.first;
        debug("%d->%d %d %d\n",root, map_x[root], map_y[root], edges[root]);
        ans += (int64_t)map_x[root] * map_y[root] - edges[root];
    }
    cout << ans << endl;
    return 0;
}
