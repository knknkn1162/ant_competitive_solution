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

vector<vector<double>> combi;
void init_combi(int size) {
    combi.resize(size+1);
    for(int i = 0; i <= size; i++) combi[i].resize(size+1);
    combi[0][0] = 1;
    for(int i = 1; i <= size; i++) {
        combi[i][0] = combi[i-1][0]/2;
        for(int j = 1; j <= i; j++) {
            combi[i][j] = (combi[i-1][j-1] + combi[i-1][j])/2;
        }
    }
}

#define EPS (1e-4)
int main(void) {
    int num, move;
    cin >> num >> move;
    pii goal;
    cin >> goal.first >> goal.second;
    if(goal.first%move || goal.second%move) {
        cout << 0 << endl;
        return 0;
    }
    init_combi(num);
    goal = make_pair(
        goal.first/move,
        goal.second/move
    );
    double ans = 0;
    for(int right = 0; right <= num; right++) {
        int left = right - goal.first;
        if(left < 0) continue;
        int rem = num - (left + right);
        if(rem < 0) continue;
        int base = (rem - goal.second)/2;
        int up = base + goal.second;
        int down = base;
        if(up + down != rem || up < 0 || down < 0) continue;
        // right(x+), left(x-), up(y+), down(y-)
        debug("->%d, <-%d,  up: %d, down: %d\n",
            right, left, up, down
        );
        double res = combi[num][right+left];
        res *= combi[right+left][left];
        res *= combi[up+down][down];
        ans += res;
    }
    printf("%.10lf\n", ans);
    return 0;
}
