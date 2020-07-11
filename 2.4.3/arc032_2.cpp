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
#include <cmath> // sqrt
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
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

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

int main(void) {
    int vs, es;
    cin >> vs >> es;
    Ufind ufind(vs);
    int cnt = 0;
    for(int i = 0; i < es; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        if(ufind.is_connect(v1, v2)) continue;
        cnt++;
        ufind.unite(v1, v2);
    }

    cout << (vs-1-cnt) << endl;
    return 0;
}
