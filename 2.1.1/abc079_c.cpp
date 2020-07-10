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


#define TARGET 7
int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    vector<int> arr(len);
    for(int i = 0; i < len; i++) {
        arr[i] = str[i] - '0';
    }

    for(int pat = 0; pat < (1<<(len-1)); pat++) {
        // arr[i] * arr[i+1]
        int num = arr[0];
        string str;
        str.push_back(arr[0] + '0');
        for(int bit = 0; bit < len-1; bit++) {
            // plus
            if(pat & (1<<bit)) {
                num += arr[bit+1];
                str.push_back('+');
            } else {
                num -= arr[bit+1];
                str.push_back('-');
            }
            str.push_back(arr[bit+1]+'0');
        }
        if(num == TARGET) {
            cout << str << "=7" << endl;
            return 0;
        }
    }
    __builtin_unreachable();
    return 0;
}
