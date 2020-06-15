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
    cin >> num;
    vector<int> vec(num);
    int i;
    int ave = 0;
    for(i = 0; i < num; i++) {
        cin >> vec[i];
        ave += vec[i];
    }
    ave /= num;
    for(i = 0; i < num; i++) {
        cout << abs(vec[i]-ave) << endl;
    }
    return 0;
}
