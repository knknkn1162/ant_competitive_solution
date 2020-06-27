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
#else
#define debug(fmt, ...)
#endif

int main(void) {
    int num;
    cin >> num;
    vector<int> primes(num+1);
    for(int i = 1; i <= num; i++) {
        primes[i] = i;
    }

    vector<int> cnt(num+1, 1);
    for(int i = 2; i <= num; i++) {
        if(primes[i] == 1) continue;
        int p = primes[i];
        for(int j = i; j <= num; j+=i) {
            int m = 0;
            while(1) {
                if(primes[j]%p) break;
                primes[j] /= p;
                m++;
            }
            cnt[j] *= (m + 1);
        }
    }
    int64_t sum = 0;
    for(int i = 1; i <= num; i++) {
        sum += (int64_t)i * cnt[i];
    }
    cout << sum << endl;
    return 0;
}
