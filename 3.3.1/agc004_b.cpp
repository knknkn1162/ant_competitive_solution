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

#define INF (1e+9)
struct range {
    int start;
    int end;
};

#define ROOT_NODE 1
#define BIG_INF (1e+15)

bool is_overlap(struct range r1, struct range r2) {
    return r1.end > r2.start && r2.end > r1.start;
}

bool is_contain(struct range r, struct range box) {
    return box.start <= r.start && r.end <= box.end;
}

int get_min(vector<int>& seg, struct range r, int node, struct range nr) {
    if(!is_overlap(r, nr)) return INF;
    if(is_contain(nr, r)) return seg[node];
    struct range left = {nr.start, (nr.start + nr.end)/2};
    struct range right = {(nr.start + nr.end) / 2, nr.end};
    int m1 = get_min(seg, r, node*2, left);
    int m2 = get_min(seg, r, node*2+1, right);
    return min(m1, m2);
}

int main(void) {
    int num;
    int64_t magic;
    cin >> num >> magic;
    vector<int> arr(num);
    cins(arr);
    int size = num * 2;
    int size2 = 1;
    while(size > size2) size2 *= 2;
    vector<int> seg(size2*2, INF+1);
    for(int i = 0; i < size; i++) {
        seg[size2+i] = arr[i%num];
    }
    for(int i = size2-1; i >= 0; i--) {
        seg[i] = min(seg[i*2], seg[i*2+1]);
    }

    int64_t ans = BIG_INF;
    struct range whole = {0, size2};
    for(int k = 0; k <= num-1; k++) {
        int64_t res = 0;
        // pick up slime
        for(int slime = num-1; slime >= 0; slime--) {
            int idx = slime + num;
            struct range r = {idx-k, idx+1};
            int change = get_min(seg, r, ROOT_NODE, whole);
            res += change;
            debug("%d -> %d\n", slime, res);
        }
        debug("k: %d -> %lld+%lld\n", k, res, magic*k);
        res += magic * k;
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
