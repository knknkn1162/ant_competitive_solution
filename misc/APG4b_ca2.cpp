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
typedef pair<int,int> pii;

int main(void) {
    int num;
    cin >> num;
    vector<pii> pairs(num);
    for(auto& elem: pairs) {
        cin >> elem.first >> elem.second;
    }
    auto cmp = [](pii p1, pii p2) {
        return p1.second < p2.second;
    };
    sort(pairs.begin(), pairs.end(), cmp);

    for(auto& elem: pairs) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}
