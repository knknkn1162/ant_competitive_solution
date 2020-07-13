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


int main(void) {
    int64_t num;
    cin >> num;
    if(num == 1) {
        cout << "Deficient" << endl;
        return 0;
    }
    int64_t num_2 = sqrt(0.5 + num);

    int64_t sum = 1;
    for(int sval = 2; sval <= num_2; sval++) {
        if(num%sval) continue;
        int64_t bval = num/sval;
        sum += sval;
        if(sval == bval) continue;
        sum += bval;
    }
    debug("%ld\n", sum);
    string str;
    if(sum == num) {
        str = "Perfect";
    } else if (sum < num) {
        str = "Deficient";
    } else {
        str = "Abundant";
    }
    cout << str << endl;
    return 0;
}
