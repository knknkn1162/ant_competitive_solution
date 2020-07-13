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
typedef pair<double, double> pdd;
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

#define INF 100

pii dir4[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
#define _x first
#define _y second

int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> mat(row+2, vector<int>(col+2));
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            mat[i][j] = str[j-1] - '0';
        }
    }

    vector<vector<int>> ans(row+2, vector<int>(col+2));
    for(int i = 2; i <= row-1; i++) {
        for(int j = 2; j <= col-1; j++) {
            int val = INF;
            for(auto d: dir4) {
                pii np = make_pair(
                    i + d._x,
                    j + d._y
                );
                val = min(val, mat[np._x][np._y]);
            }
            debug("mat[%d][%d] = %d\n", i, j, val);
            ans[i][j] = val;
            for(auto d: dir4) {
                pii np = make_pair(
                    i + d._x,
                    j + d._y
                );
                mat[np._x][np._y] -= val;
            }
        }
    }

    // presettation
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            putchar(ans[i][j] + '0');
        }
        putchar('\n');
    }
    return 0;
}
