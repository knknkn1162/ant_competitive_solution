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
    int num;
    cin >> num;
    int total = num*(num-1)/2;

    map<pii, vector<pii>> graph;
    // vector<vector<int>> graph(num*num);
    vector<vector<pii>> matches(num, vector<pii>(num-1));
    // vector<vector<int>> matches(num, vector<int>(num-1));
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num-1; j++) {
            int target;
            cin >> target;
            target--;
            int smaller = min(i, target);
            int larger = max(i, target);
            pii p = make_pair(smaller, larger);
            matches[i][j] = p;
        }
    }

    map<pii, int> outdeg;
    for(int i = 0; i < num; i++) {
        pii prev = matches[i][0];
        for(int j = 1; j < num-1; j++) {
            pii cur = matches[i][j];
            graph[prev].push_back(cur);
            outdeg[cur]++;
            prev = cur;
        }
    }

    queue<pii> queue;
    for(int i = 0; i < num; i++) {
        for(int j = i+1; j < num; j++) {
            pii p = make_pair(i, j);
            if(outdeg[p]) continue;
            queue.push(p);
        }
    }

    int cnt = 0;
    // 1-indexed
    int ans = 1;
    vector<char> bitmap(num);
    while(!queue.empty()) {
        pii src = queue.front(); queue.pop();
        debug("pii: %d, %d\n", src.first, src.second);
        cnt++;
        if(bitmap[src.first] || bitmap[src.second]) {
            ans++;
            fill(bitmap.begin(), bitmap.end(), 0);
        }
        bitmap[src.first] = bitmap[src.second] = 1;
        for(pii dst: graph[src]) {
            // circuit
            outdeg[dst]--;
            if(!outdeg[dst]) queue.push(dst);
        }
    }
finish:
    debug("cnt: %d ans: %d\n", cnt, ans);
    cout << (cnt < total ? -1 : ans) << endl;
    return 0;
}
