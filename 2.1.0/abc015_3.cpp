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

bool sanity_check(vector<vector<int>>& mat, int idx, int point) {
    if(idx == mat.size()) {
        return point != 0;
    }
    bool flag = true;
    for(int i = 0; i < mat[idx].size(); i++) {
        flag &= sanity_check(mat, idx+1, point ^ mat[idx][i]);
    }
    return flag;
}

int main(void) {
    int num, k;
    cin >> num >> k;
    vector<vector<int>> mat(num, vector<int>(k));
    // parse stdin
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < k; j++) {
            int t;
            cin >> t;
            mat[i][j] = t;
        }
    }

    cout << (sanity_check(mat, 0, 0) ? "Nothing" : "Found") << endl;
    return 0;
}
