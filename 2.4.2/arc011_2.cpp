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
#include <cmath> // sqrt
#define _GLIBCXX_DEBUG // check []
#define DIVISOR 1000000007

using namespace std;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
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

vector<int> table(256);

void init_table(void) {
    table['b'] = table['c'] = 1;
    table['d'] = table['w'] = 2;
    table['t'] = table['j'] = 3;
    table['f'] = table['q'] = 4;
    table['l'] = table['v'] = 5;
    table['s'] = table['x'] = 6;
    table['p'] = table['m'] = 7;
    table['h'] = table['k'] = 8;
    table['n'] = table['g'] = 9;
    table['z'] = table['r'] = 10;
}

int main(void) {
    string str;
    int num;
    cin >> num;
    init_table();
    vector<string> ans;
    for(int i = 0; i < num; i++) {
        string str;
        cin >> str;
        int len = str.length();
        string res;
        for(int j = 0; j < len; j++) {
            str[j] = tolower(str[j]);
            int d = table[str[j]];
            if(d) res.push_back(d%10 + '0');
        }
        if(res.length()) ans.push_back(res);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size()-1) cout << ' ';
    }
    cout << endl;
    return 0;
}
