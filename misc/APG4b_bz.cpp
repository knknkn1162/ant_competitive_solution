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

int main(void) {
    int num;
    cin >> num;
    map<int, int> map;
    for(int i = 0; i < num; i++) {
        int val;
        cin >> val;
        map[val]++;
    }

    int mmax = 0;
    int argmax;
    for(auto& elem: map) {
        if(mmax < elem.second) {
            mmax = elem.second;
            argmax = elem.first;
        }
    }
    cout << argmax << " " << mmax << endl;
    return 0;
}
