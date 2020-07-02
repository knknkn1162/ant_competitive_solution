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
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

pii next_dir[2] = {
    {1, 0},
    {0, 1},
};

enum type {
    TYPE_NONE,
    TYPE_CHECKED,
};

void dfs(vector<vector<char>>& map, pii p) {
    map[p.first][p.second] = TYPE_NONE;
    debug("%d, %d\n", p.first, p.second);
    for(pii d: next_dir) {
        pii np = make_pair(
            p.first + d.first,
            p.second + d.second
        );
        if(map[np.first][np.second] == TYPE_NONE) continue;
        dfs(map, np);
        break;
    }
    return;
}

int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> map(row+2, vector<char>(col+2));
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            map[i][j] = (str[j-1] == '#');
        }
    }

    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(map[i][j] == TYPE_CHECKED) {
                dfs(map, make_pair(i, j));
                goto finish;
            }
        }
    }
finish:
    bool ans = 1;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(map[i][j] == TYPE_CHECKED) ans = 0;
        }
    }
    cout << (ans ? "Possible" : "Impossible") << endl;
    return 0;
}
