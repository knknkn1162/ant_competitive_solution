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
#define DIVISOR 1000000007

using namespace std;
typedef pair<int,int> pii;
typedef pair<int64_t, int64_t> pII;

template<typename T>
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#define ps(arr) \
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

#include <list>
int main(void) {
    string str;
    cin >> str;
    list<char> list;
    for(int i = 0; i < str.length(); i++) {
        list.push_back(str[i]);
    }
    int qs;
    cin >> qs;
    int dir = 1;
    for(int i = 0; i < qs; i++) {
        int type, pos;
        char ch;
        cin >> type;
        switch(type) {
            case 1:
                dir = -dir;
                break;
            case 2:
                {
                    cin >> pos; cin >> ch;
                    int is_head = (dir == 1 && pos == 1);
                    is_head |= (dir == -1 && pos == 2);
                    if(is_head) {
                        list.push_front(ch);
                    } else {
                        list.push_back(ch);
                    }
                }
                break;
            default:
                break;
        }
        ps(list);
    }
    if(dir == -1) reverse(list.begin(), list.end());
    for(auto it = list.begin(); it != list.end(); it++) {
        cout << *(it);
    }
    cout << endl;
    return 0;
}
