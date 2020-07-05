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

pii dir4[4] = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1},
};

#define INF 100000

int main(void) {
    int row, col;
    cin >> row >> col;

    vector<vector<char>> map(row+2, vector<char>(col+2));
    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            map[i][j] = (str[j-1] == '.');
        }
    }

    int vs = (row+2) * (col+2);
    vector<vector<int>> graph(vs, vector<int>(vs, INF));
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            int src = i * (col+2) + j;
            if(!map[i][j]) continue;
            for(auto d: dir4) {
                pii np = make_pair(
                    i + d.first,
                    j + d.second
                );
                if(!map[np.first][np.second]) continue;
                int dst = np.first * (col+2) + np.second;
                graph[src][dst] = 1;
            }
        }
    }
    for(int i = 0; i < vs; i++) graph[i][i] = 0;

    // Warshal Floyd
    for(int k = 0; k < vs; k++) {
        for(int i = 0; i < vs; i++) {
            for(int j = 0; j < vs; j++) {
                if(graph[i][k] == INF) continue;
                if(graph[k][j] == INF) continue;
                int nnew = graph[i][k] + graph[k][j];
                graph[i][j] = min(
                    graph[i][j],
                    nnew
                );
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < vs; i++) {
        for(int j = 0; j < vs; j++) {
            if(graph[i][j] == INF) continue;
            ans = max(ans, graph[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
