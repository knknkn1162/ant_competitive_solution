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

int main(void) {
    int num;
    int sum;
    cin >> num >> sum;
    vector<int> arr(num), brr(num);
    for(int &elem: arr) cin >> elem;
    for(int &elem: brr) cin >> elem;

    int ans = 0;
    for(int a: arr) {
        for(int b: brr) {
            ans += (a + b == sum);
        }
    }
    cout << ans << endl;
    return 0;
}
