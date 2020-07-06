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
#include <cmath>
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


string get_half(string& str, int k) {
    int offset = 0;
    int pos = 0;
    for(int i = 0; i < str.length(); i++) {
        offset += (str[i] != 'x');
        if(k == offset) {
            pos = i;
            break;
        }
    }
    return str.substr(0, pos+1);
}


int main(void) {
    string str;
    string str_x;
    cin >> str;
    int len = str.length();
    int sum = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] != 'x') {
            sum++;
            str_x.push_back(str[i]);
        }
    }
    if(str_x.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < str_x.length(); i++) {
        if(str_x[i] != str_x[str_x.length()-1-i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    debug("%d\n", sum);
    vector<string> half(2);
    half[0] = get_half(str, (sum+1)/2);
    reverse(str.begin(), str.end());
    half[1] = get_half(str, (sum+1)/2);
    debug("%s vs %s\n", half[0].c_str(), half[1].c_str());

    vector<int> map(len+1);
    for(int k = 0; k < 2; k++) {
        int res = 0;
        for(int i = 0, idx = 0; i < half[k].length(); i++) {
            if(half[k][i] != 'x') {
                map[idx] = max(map[idx], res);
                idx++;
                res = 0;
            } else {
                res++;
            }
        }
    }

    int x_sum = 0;
    ps(map);
    for(int i = 0; i <= len; i++) {
        x_sum += map[i];
    }

    int ans_len = (str_x.length()+1)/2 + x_sum;
    debug("result length: %d\n", ans_len);
    cout << (ans_len - half[0].length()) + (ans_len - half[1].length()) << endl;
    return 0;
}
