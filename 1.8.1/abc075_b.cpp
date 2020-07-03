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


pii dir8[8] = {
    {0, -1},
    {0, 1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {1, -1},
    {1, 0},
    {1, 1},
};

int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> map(row+2, vector<char>(col+2, '.'));

    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            map[i][j] = str[j-1];
        }
    }

    vector<vector<char>> ans(row+2, vector<char>(col+2, '#'));
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(map[i][j] == '#') continue;
            int cnt = 0;
            for(pii d: dir8) {
                pii np = make_pair(
                    i+d.first,
                    j+d.second
                );
                cnt += (map[np.first][np.second] == '#');
            }
            ans[i][j] = cnt + '0';
        }
    }

    // presentation
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            putchar(ans[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
