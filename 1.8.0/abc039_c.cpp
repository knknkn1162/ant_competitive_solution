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

// 白黒白黒白白黒白黒白黒白
char table[][5] = {
    "Do", "Do",
    "Re", "Re",
    "Mi",
    "Fa", "Fa",
    "So", "So",
    "La", "La",
    "Si",
};

char colors[] = "WBWBWWBWBWBW";
int main(void) {
    string str;
    cin >> str;
    for(int offset = 0; offset < 12; offset++) {
        bool flag = 1;
        for(int j = 0; j < str.length(); j++) {
            int idx = (j + offset)%12;
            flag &= (str[j] == colors[idx]);
        }
        if(flag) {
            cout << table[offset] << endl;
            return 0;
        }
        debug("%d\n", flag);
    }
    return 0;
}
