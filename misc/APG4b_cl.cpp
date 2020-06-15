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
    int num;
    cin >> num;
    int val;
    cin >> val;
    int i;
    for(i = 1; i <= num; i++) {
        char op;
        int b;
        cin >> op >> b;
        bool flag = 1;
        switch(op) {
            case '+':
                val += b;
                break;
            case '-':
                val -= b;
                break;
            case '*':
                val *= b;
                break;
            case '/':
                if(b == 0) {
                    flag = 0;
                } else {
                    val /= b;
                }
                break;
            case '?':
            case '=':
            case '!':
                flag = 0;
                break;
            default:
                break;
        }
        if(!flag) {
            cout << "error" << endl;
            break;
        }
        cout << i << ":" << val << endl;
    }
    return 0;
}
