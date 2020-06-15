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

const int num = 5;
int main(void) {
    vector<int> arr(num);
    for(int &elem: arr) cin >> elem;
    int prev = 0;
    int flag = 0;
    for(int cur: arr) {
        if(cur == prev) { flag = 1; break; }
        prev = cur;
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}
