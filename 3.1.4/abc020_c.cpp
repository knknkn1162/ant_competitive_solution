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

#define TIME_MAX (1e+9)

pii dist[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

#define INF (1e+15)
typedef pair<int64_t,pii> tstamp;
int64_t judge(vector<vector<char>>& mat,
    vector<vector<char>>& check,
    pii start, pii goal, int64_t key) {

    priority_queue<tstamp, vector<tstamp>, greater<tstamp>> min_queue;
    min_queue.push(make_pair(0, start));
    while(!min_queue.empty()) {
        tstamp ts= min_queue.top(); min_queue.pop();
        int64_t time = ts.first;
        pii p = ts.second;
        debug("%d, %d -> %lld\n", p.first, p.second, time);
        if(p == goal) {
            return time;
        }
        if(check[p.first][p.second]) continue;
        check[p.first][p.second] = 1;

        for(pii dir: dist) {
            pii np = make_pair(
                p.first+dir.first,
                p.second+dir.second
            );
            if(!mat[np.first][np.second]) continue;
            int64_t ntime = time;
            if(mat[np.first][np.second] == 2) {
                ntime++;
            } else {
                ntime += key;
            }
            min_queue.push(make_pair(ntime, np));
        }
    }
    return 0;
}

int main(void) {
    int row, col;
    int64_t time;
    cin >> row >> col >> time;
    vector<vector<char>> mat(row+2, vector<char>(col+2));
    pii start, goal;
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
            mat[i][j] = (ch == '#') ? 1 : 2;
        }
    }

    int low = -1;
    int high = TIME_MAX+1;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        vector<vector<char>> check(row+2, vector<char>(col+2));
        int64_t elapse = judge(mat, check, start, goal, mid);
        debug("%d -> %d\n", mid, elapse);
        if(elapse <= time) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << endl;
    return 0;
}
