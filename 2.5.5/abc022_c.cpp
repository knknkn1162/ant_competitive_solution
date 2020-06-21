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

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T>& arr) { for(T e: arr) p(e); }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

struct edge {
    int v1;
    int v2;
    int vs;
};

#define INF ((1e+9)+1)
int dijkstra(vector<vector<pii>>& mat, int start, int goal) {
    priority_queue<pii, vector<pii>,greater<pii>> min_queue;
    // make_pair(cost, v)
    min_queue.push(make_pair(0, start));
    vector<int> tmp(mat.size(), INF);
    while(!min_queue.empty()) {
        pii p = min_queue.top(); min_queue.pop();
        debug("%d %d\n", p.second, p.first);
        if(p.second == goal) {
            return p.first;
        }
        int src = p.second;
        for(pii elem: mat[src]) {
            int dst = elem.second;
            int nnew = elem.first+p.first;
            if(tmp[dst] > nnew) {
                tmp[dst] = nnew;
                min_queue.push(make_pair(nnew, dst));
            }
        }
    }
    return INF;
}

int main(void) {
    int vs, es;
    cin >> vs >> es;
    vector<vector<int>> mat(vs, vector<int>(vs, INF));
    vector<pii> cands;
    for(int i = 0; i < es; i++) {
        int v1, v2, len;
        cin >> v1 >> v2 >> len;
        v1--; v2--;
        if(v1 == 0 || v2 == 0) {
            cands.push_back(make_pair(len, v1+v2));
        } else {
            mat[v1][v2] = mat[v2][v1] = len;
        }
    }

    // Warshal Floyd
    for(int k = 0; k < vs; k++) {
        for(int i = 0; i < vs; i++) {
            for(int j = 0; j < vs; j++) {
                int nnew = mat[i][k] + mat[j][k];
                if(nnew >= INF) continue;
                mat[i][j] = min(mat[i][j], nnew);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < cands.size(); i++) {
        for(int j = i+1; j < cands.size(); j++) {
            pii ps = cands[i];
            pii pg = cands[j];
            ans = min(ans, ps.first + pg.first + mat[ps.second][pg.second]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
