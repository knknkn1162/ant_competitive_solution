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

pii dir4[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

enum type {
    TYPE_NONE,
    TYPE_WALL,
    TYPE_PATH
};

int64_t judge(vector<vector<char>>& map, pii start, pii goal, int64_t key) {
    int row = map.size();
    int col = map[0].size();
    vector<vector<int64_t>> time_table(row, vector<int64_t>(col, INF+1));
    queue<pii> queue;
    queue.push(start);
    time_table[start.first][start.second] = 0;
    // BFS
    while(!queue.empty()) {
        pii p = queue.front();  queue.pop();
        debug("%d, %d\n", p.first, p.second);
        if(p == goal) break;
        for(pii d: dir4) {
            pii np = make_pair(
                p.first + d.first,
                p.second + d.second
            );
            if(!map[np.first][np.second]) continue;
            int64_t ntime = time_table[p.first][p.second];
            if(map[np.first][np.second] == TYPE_WALL) {
                ntime += key;
            } else {
                ntime++;
            }
            // update if necessary
            if(time_table[np.first][np.second] > ntime) {
                time_table[np.first][np.second] = ntime;
                queue.push(np);
            }
        }
    }
    debug("key: %lld -> time: %lld\n", key, time_table[goal.first][goal.second]);
    return time_table[goal.first][goal.second];
}

int main(void) {
    int row, col;
    int64_t limit;
    cin >> row >> col >> limit;
    pii start, goal;
    vector<vector<char>> map(row+2, vector<char>(col+2));
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            char ch = str[j-1];
            if(ch == 'S') {
                start = make_pair(i, j);
            } else if (ch == 'G') {
                goal = make_pair(i, j);
            }
            map[i][j] = (ch == '#') ? TYPE_WALL : TYPE_PATH;
        }
    }

    int64_t low = 0;
    int64_t high = INF+1;
    while(low + 1 < high) {
        int64_t mid = (low + high) / 2;
        if(judge(map, start, goal, mid) <= limit) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << endl;
    return 0;
}
