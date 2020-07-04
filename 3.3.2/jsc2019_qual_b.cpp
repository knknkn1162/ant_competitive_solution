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
#define ps(arr) \
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif


#define ROOT_NODE 1

void add(vector<int>& seg, int size, int idx, int val) {
    int node = size + idx;
    while(node) {
        seg[node]++;
        node = node/2;
    }
    return;
}

bool is_overlap(pii r1, pii r2) {
    return r1.second > r2.first && r2.second > r1.first;
}

bool is_contain(pii t, pii box) {
    return box.first <= t.first && t.second <= box.second;
}

int get_sum(vector<int>& seg, pii r, int node, pii nr) {
    if(!is_overlap(r, nr)) return 0;
    if(is_contain(nr, r)) return seg[node];
    pii left = make_pair(nr.first, (nr.first+nr.second)/2);
    pii right = make_pair((nr.first+nr.second)/2, nr.second);
    int s1 = get_sum(seg, r, node*2, left);
    int s2 = get_sum(seg, r, node*2+1, right);
    return s1+s2;
}
#define VAL_MAX 2000
#define VAL2_MAX (1<<11)
int main(void) {
    int num,k;
    cin >> num >> k;
    vector<int> arr(num*2);
    for(int i = 0; i < num; i++) {
        int val;
        cin >> val;
        val--;
        arr[i] = arr[i+num] = val;
    }
    vector<int> seg(VAL2_MAX*2);

    pii whole = make_pair(0, VAL2_MAX);
    vector<int> res(num*2);
    for(int i = 0; i < num*2; i++) {
        int val = arr[i];
        pii range = make_pair(val+1, VAL2_MAX);
        res[i] = get_sum(seg, range, ROOT_NODE, whole);
        debug("[val %d]%d -> %d\n", val, i, res[i]);
        add(seg, VAL2_MAX, val, 1);
    }

    int64_t sum = 0;
    int64_t sum_k = ((int64_t)k * (k-1) / 2)%DIVISOR;
    for(int i = 0; i < num; i++) {
        int64_t init = res[i];
        int64_t d = res[num+i]-init;
        debug("seq init: %d, d: %d, k: %d\n", init, d, k);
        int64_t res = (init*k)%DIVISOR;
        sum = (sum + res)%DIVISOR;
        res = (sum_k * d)%DIVISOR;
        sum = (sum + res)%DIVISOR;
    }
    cout << sum << endl;
    return 0;
}
