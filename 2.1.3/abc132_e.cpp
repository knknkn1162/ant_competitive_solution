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

int main(void) {
    int vs, es;
    cin >> vs >> es;
    int vs3 = vs*3;
    vector<vector<int>> mat(vs3);
    for(int i = 0; i < es; i++) {
        int src, dst;
        cin >> src >> dst;
        // 0-indexed
        src--; dst--;
        // v1*3 -> v2*3+1
        for(int j = 0; j < 3; j++) {
            int nj = (j+1)%3;
            mat[src*3+j].push_back(dst*3+nj);
        }
    }
    int start, goal;
    cin >> start >> goal;
    start--; goal--;
    debug("start: %d goal: %d\n", start, goal);

    // bfs
    // <int,int> = (v, cnt)
    queue<pii> queue;
    vector<char> checked(vs3);
    checked[start*3] = 1;
    queue.push(make_pair(start*3, 0));
    int ans = -1;
    while(!queue.empty()) {
        pii p = queue.front(); queue.pop();
        if(p.first == goal*3) {
            ans = p.second/3;
            break;
        }
        for(int elem: mat[p.first]) {
            if(checked[elem]) continue;
            checked[elem] = 1;
            queue.push(make_pair(elem, p.second+1));
        }
    }
    printf("%d\n", ans);
    return 0;
}
