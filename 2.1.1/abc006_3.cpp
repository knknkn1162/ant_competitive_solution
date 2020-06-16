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
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T>& arr) { for(T e: arr) p(e); }

int main(void) {
    int num, legs;
    cin >> num >> legs;
    int m = legs - 2*num;
    tuple<int,int,int> ans = make_tuple(-1,-1,-1);
    for(int b = 0; b <= m; b++) {
        int rem = m - b;
        if(rem%2) continue;
        int c = rem/2;
        int a = num - b - c;
        if(a < 0) continue;
        ans = make_tuple(a,b,c);
        break;
    }
    cout << get<0>(ans) << " ";
    cout << get<1>(ans) << " ";
    cout << get<2>(ans) << endl;
    return 0;
}
