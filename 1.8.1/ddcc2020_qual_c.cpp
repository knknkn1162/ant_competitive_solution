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
#include <cmath>
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


int main(void) {
    int row, col, k;
    cin >> row >> col >> k;
    vector<vector<char>> mat(row+2, vector<char>(col+2));
    int start = 0;
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        bool is_empty = true;
        for(int j = 1; j <= col; j++) {
            bool flag = (str[j-1] == '#');
            if(flag) is_empty = false;
            mat[i][j] = flag;
        }
        if((!is_empty) && (!start)) {
            start = i;
        }
    }
    debug("start: %d\n", start);

    int idx = 1;
    vector<vector<int>> ans(row+2, vector<int>(col+2));
    for(int i = start; i <= row; i++) {
        int cnt = 0;
        for(int j = 1; j <= col; j++) {
            cnt += mat[i][j];
            if(mat[i][j] && cnt > 1) idx++;
            ans[i][j] = idx;
        }
        if(cnt == 0) {
            for(int j = 1; j <= col; j++) {
                ans[i][j] = ans[i-1][j];
            }
        } else {
            idx++;
        }
        debug("%d\n", idx);
    }

    for(int i = start-1; i >= 1; i--) {
        for(int j = 1; j <= col; j++) {
            ans[i][j] = ans[i+1][j];
        }
    }

    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            cout << ans[i][j];
            cout << (j == col ? '\n' : ' ');
        }
    }
    return 0;
}
