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

using namespace std;

template<typename T>
void cins(vector<T> arr) { for(T e: arr) cin >> e; }
template<typename T>
void cins(vector<vector<T>> mat) { 
}

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T> arr) { for(T e: arr) p(e); }

int main(void) {
    int cnt = 0;
    for(int i = 1; i <= 9 ; i++) {
        for(int j = 1; j <= 9; j++) {
            int res;
            cin >> res;
            cnt += (res == i*j);
        }
    }

    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            cout << i*j;
            cout << (j == 9 ? '\n' : ' ');
        }
    }
    p(cnt);
    p(9*9-cnt);
    return 0;
}
