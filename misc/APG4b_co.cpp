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

using namespace std;

enum type {
    TYPE_NOTEXT = 1,
    TYPE_TEXT = 2,
};

int main(void) {
    int type;
    string text;
    int price, num;
    cin >> type;
    switch(type) {
        case TYPE_NOTEXT:
            break;
        case TYPE_TEXT:
            cin >> text;
            cout << text << "!" << endl;
            break;
        default:
            break;
    }
    cin >> price >> num;
    cout << price * num << endl;
    return 0;
}
