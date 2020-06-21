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

#define BASE 13

int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    vector<vector<int64_t>> dp(len+1, vector<int64_t>(BASE));
    dp[0][0] = 1;
    for(int i = 1; i <= len; i++) {
        char ch = str[i-1];
        for(int j = 0; j < 10; j++) {
            if(ch == '?' || ch == j+'0') {
                for(int k = 0; k < BASE; k++) {
                    int nnew = (k*10+j)%BASE;
                    dp[i][nnew] = (dp[i-1][k] + dp[i][nnew])%DIVISOR;
                }
            }
        }
    }
    cout << dp[len][5] << endl;
    return 0;
}
