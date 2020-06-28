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
#else
#define debug(fmt, ...)
#endif

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) { return b; }
    return gcd(b%a, a);
}

int main(void) {
    int64_t a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    int64_t mmax = gcd(a,b);
    int64_t mmax_2 = sqrt(0.5 + mmax);
    map<int64_t, int> cnt;
    cnt[1] = 1;
    int prime = 2;
    while(mmax > 1) {
        // mmax itself is prime
        if(prime > mmax_2) {
            cnt[mmax] = 1;
            break;
        }
        if(mmax % prime) { prime++; continue; }
        mmax /= prime;
        cnt[prime] = 1;
    }

    cout << cnt.size() << endl;
    return 0;
}
