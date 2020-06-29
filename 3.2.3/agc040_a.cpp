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

int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    str += '0'; // for guard
    vector<int> rle;
    char prev = '<';
    int cnt = 0;
    for(int i = 0; i < len+1; i++) {
        char cur = str[i];
        if(cur == prev) {
            cnt++;
        } else {
            rle.push_back(cnt);
            cnt = 1;
        }
        prev = cur;
    }
    int size = rle.size();
    rle.push_back(0);
    ps(rle);
    int64_t sum = 0;
    for(int i = 0; i < size; i+=2) {
        int mmax = max(rle[i], rle[i+1]);
        sum += mmax;
        if(rle[i]) {
            int64_t left = rle[i]-1;
            sum += (left+1) * left/2;
        }
        if(rle[i+1]) {
            int64_t right = rle[i+1]-1;
            sum += (right+1) * right/2;
        }
    }
    cout << sum << endl;
    return 0;
}
