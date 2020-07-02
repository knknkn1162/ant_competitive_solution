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
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif

// aaabcca/aaabcca
int main(void) {
    string str;
    cin >> str;
    int len =str.length();
    str.push_back('\n');
    int k;
    cin >> k;
    vector<int> arr;
    char prev = str[0];
    int cnt = 1;
    for(int i = 1; i < str.length(); i++) {
        char cur = str[i];
        if(prev == cur) {
            cnt++;
        } else {
            arr.push_back(cnt);
            cnt = 1;
        }
        prev = cur;
    }
    ps(arr);

    int64_t sum = 0;
    if(arr.size() == 1) {
        sum = ((int64_t)arr[0] * k)/2;
    } else {
        for(int i = 1; i < arr.size()-1; i++) {
            sum += (arr[i]/2);
        }
        sum *= k;
        int64_t edge = (*arr.begin())/2 + (*(arr.end()-1))/2;
        if(str[0] != str[len-1]) {
            // (head + tail) * k
            sum += edge * k;
        } else {
            // head + (conn)*(k-1) + tail
            int conn = ((*arr.begin()) + (*(arr.end()-1)))/2;
            sum += edge + (int64_t)conn * (k-1);
        }
    }
    cout << sum << endl;
    return 0;
}
