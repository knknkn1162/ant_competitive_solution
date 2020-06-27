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

enum type {
    TYPE_NONE,
    TYPE_WALL,
    TYPE_PATH
};

pii dir4[4] = {
    { 1, 0 },
    { -1, 0 },
    { 0, -1 },
    { 0, 1 },
};

#define BREAK_MAX 2
int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> map(row+2, vector<int>(col+2));
    pii start, goal;
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            char ch = str[j-1];
            if(ch == 's') {
                start = make_pair(i, j);
            } else if(ch == 'g') {
                goal = make_pair(i, j);
            }
            map[i][j] = (ch == '#') ? TYPE_WALL : TYPE_PATH;
        }
    }
    queue<pii> queue;
    vector<vector<int>> cnt_map(row+2, vector<int>(col+2, BREAK_MAX+1));
    queue.push(start);
    cnt_map[start.first][start.second] = 0;

    int flag = 0;
    while(!queue.empty()) {
        pii p = queue.front(); queue.pop();
        debug("%d, %d -> %d\n", p.first, p.second, cnt_map[p.first][p.second]);
        if(p == goal) {
            flag = 1;
            break;
        }
        int cur = cnt_map[p.first][p.second];
        for(pii d: dir4) {
            pii np = make_pair(
                p.first + d.first,
                p.second + d.second
            );
            if(map[np.first][np.second] == TYPE_NONE) continue;
            int nbreaks = cur;
            if(map[np.first][np.second] == TYPE_WALL) nbreaks++;
            if(cnt_map[np.first][np.second] > nbreaks) {
                cnt_map[np.first][np.second] = nbreaks;
                queue.push(np);
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
