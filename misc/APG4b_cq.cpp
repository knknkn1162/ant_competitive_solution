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

int main(void) {
    int a, b;
    char op;
    cin >> a >> op >> b;
    switch(op) {
        case '+':
            cout << a+b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            if(b == 0) {
                cout << "error" << endl;
            } else {
                cout << a/b << endl;
            }
            break;
        case '?':
        case '=':
        case '!':
            cout << "error" << endl;
            break;
        default:
            break;
    }
    return 0;
}
