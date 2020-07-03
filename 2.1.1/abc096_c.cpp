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

pii dir4[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> map(row+2, vector<char>(col+2));

    for(int i = 1; i <= row; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= col; j++) {
            map[i][j] = (str[j-1] == '#');
        }
    }

    int flag = 1;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(!map[i][j]) continue;
            int is_ok = 0;
            for(pii d: dir4) {
                pii np = make_pair(
                    i + d.first,
                    j + d.second
                );
                if(map[np.first][np.second]) is_ok = 1;
            }
            if(!is_ok) { flag = 0; goto finish; }
        }
    }
finish:
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
