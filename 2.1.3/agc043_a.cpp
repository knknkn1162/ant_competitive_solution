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

#define INF 1000

pii dir4[2] = {
    {0, 1},
    {1, 0},
};

enum type {
    TYPE_NONE,
    TYPE_WALL,
    TYPE_PATH
};

typedef pair<int,int> pii;
typedef pair<int, pii> vertex;

#define breaks first
#define p second

int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> mat(row+2, vector<int>(col+2));
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            mat[i][j] = (str[j-1] == '.') ? TYPE_PATH : TYPE_WALL;
        }
    }
    pii start = make_pair(1, 1);
    pii goal = make_pair(row, col);
    vector<vector<int>> cnts(row+2, vector<int>(col+2, INF));
    // ##...##: 3
    // .....##: 1
    // ##.....: 2
    cnts[start.first][start.second] = (mat[start.first][start.second] == TYPE_WALL);

    priority_queue<vertex, vector<vertex>, greater<vertex>> queue;
    queue.push(make_pair(cnts[start.first][start.second], start));
    while(!queue.empty()) {
        vertex v = queue.top(); queue.pop();
        debug("%d, %d -> %d\n", v.p.first, v.p.second, v.breaks);
        int type = mat[v.p.first][v.p.second];
        if(v.p == goal) break;
        for(pii d: dir4) {
            pii np = make_pair(
                v.p.first + d.first,
                v.p.second + d.second
            );
            if(mat[np.first][np.second] == TYPE_NONE) continue;
            int nnew = cnts[v.p.first][v.p.second];
            if(mat[np.first][np.second] != type) nnew++;
            if(cnts[np.first][np.second] > nnew) {
                // update
                cnts[np.first][np.second] = nnew;
                queue.push(make_pair(nnew, np));
            }
        }
    }
    cout << (cnts[goal.first][goal.second]+1)/2 << endl;
    return 0;
}
