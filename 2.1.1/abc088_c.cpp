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


#define LIM 100

bool judge(vector<vector<int>> arr, vector<pii>& ps, int size) {
    for(int i = 0; i < size; i++) {
        int a = ps[i].first;
        for(int j = 0; j < size; j++) {
            int b = ps[j].second;
            if(a+b != arr[i][j]) { return 0; }
        }
    }
    return 1;
}

int main(void) {
    vector<vector<int>> arr(3, vector<int>(3));
    for(int i = 0; i < 3; i++) {
        cins(arr[i]);
    }

    vector<pii> pairs(3);
    int flag = 0;
    for(int a1 = -LIM; a1 <= LIM; a1++) {
        pairs[0] = make_pair(a1, arr[0][0] - a1);
        for(int a2 = -LIM; a2 <= LIM; a2++) {
            pairs[1] = make_pair(a2, arr[1][1]-a2);
            for(int a3 = -LIM; a3 <= LIM; a3++) {
                pairs[2] = make_pair(a3, arr[2][2]-a3);
                if(judge(arr, pairs, 3)) {
                    flag = 1;
                    goto finish;
                }
            }
        }
    }
finish:
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
