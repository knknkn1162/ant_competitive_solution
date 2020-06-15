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
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T> arr) { for(T e: arr) p(e); }

enum type {
    TYPE_NONE,
    TYPE_WIN,
    TYPE_LOSE
};

char table[3] = {
    '-', 'o', 'x'
};

int main(void) {
    int num, games;
    cin >> num >> games;
    vector<vector<int>> results(num, vector<int>(num));

    for(int i = 0; i < games; i++) {
        int win, lose;
        cin >> win >> lose;
        // 1-indexed -> 0-indexed
        win--; lose--;
        results[win][lose] = TYPE_WIN;
        results[lose][win] = TYPE_LOSE;
    }

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            cout << table[results[i][j]];
            cout << (j == num-1 ? '\n' : ' ');
        }
    }
    return 0;
}
