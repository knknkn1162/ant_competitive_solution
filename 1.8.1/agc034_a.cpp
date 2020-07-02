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
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

bool is_reach(string& str, pii p) {
    int cur = p.first;
    while(cur < p.second) {
        if(str[cur] == '#') {
            return false;
        }
        if(str[cur+1] == '#') {
            cur+=2;
        } else {
            cur++;
        }
    }
    return true;
}

int main(void) {
    int len;
    pii move1, move2;
    cin >> len;
    cin >> move1.first >> move2.first;
    cin >> move1.second >> move2.second;
    move1.first--; move1.second--;
    move2.first--; move2.second--;
    string str;
    cin >> str;

    // assume that a < b
    bool flag = 0;
    int b = move2.first;
    bool is_ok = 0;
    if(!is_reach(str, move1) || !is_reach(str, move2)) {
        debug("%s\n", "ng");
        goto finish;
    }

    // Does move1 pass move2?
    if(move1.second < move2.second) {
        flag = 1;
        goto finish;
    }
    while(1) {
        debug("move2: %d, %d -> %d\n", b, move2.second, is_ok);
        if(b == move2.second) {
            // 7 1 3 7 6
            // .#.#....
            flag = is_ok || (str[b+1] != '#' && str[b-1] != '#');
            break;
        }
        if(str[b] == '#') {
            flag = 0;
            break;
        } else if(str[b+1] == '#') {
            b+=2;
        } else {
            if(str[b-1] != '#') is_ok = 1;
            b++;
        }
    }
finish:
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
