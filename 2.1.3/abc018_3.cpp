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

pii dir[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

#define INF (1e+9)
int main(void) {
    int row, col, sz;
    cin >> row >> col >> sz;
    queue<pii> queue;
    vector<vector<int>> dist(row+2, vector<int>(col+2));
    // need to update
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j < col; j++) {
            dist[i][j] = INF;
        }
    }

    // initialization for queue and dist
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            if(str[j-1] == 'x') {
                queue.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

    while(!queue.empty()) {
        pii p = queue.front(); queue.pop();
        int nval = dist[p.first][p.second] + 1;
        // skip
        if(nval > sz-1) continue;
        for(pii d: dir) {
            pii np = make_pair(
                p.first + d.first,
                p.second + d.second
            );
            if(dist[np.first][np.second] > nval) {
                dist[np.first][np.second] = nval;
                queue.push(np);
            }
        }
    }

    int ans = 0;
    for(int i = sz; i <= row-sz+1; i++) {
        for(int j = sz; j <= col-sz+1; j++) {
            debug("%d, %d -> %d\n", i, j, dist[i][j]);;
            if(dist[i][j] > sz-1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
