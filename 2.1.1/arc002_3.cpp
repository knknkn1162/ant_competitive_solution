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


#define INF 1000000
int main(void) {
    int num;
    cin >> num;
    string str;
    cin >> str;

    string command = "ABXY";
    int len = command.length();

    vector<string> cands;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            string tmp;
            tmp.push_back(command[i]); tmp.push_back(command[j]);
            cands.push_back(tmp);
        }
    }

    int sz = cands.size();
    int ans = INF;
    for(int i = 0; i < sz; i++) {
        for(int j = i+1; j < sz; j++) {
            vector<string> comms(2);
            comms[0] = cands[i]; comms[1] = cands[j];
            int count = 0;
            int flag = 0;
            // greedy
            for(int k = 0; k < str.length(); k++) {
                if(flag) { flag = 0; continue; }
                for(int m = 0; m < 2; m++) {
                    if(!str.compare(k, 2, comms[m])) {
                        flag = 1;
                    }
                }
                count++;
            }
            debug("%s, %s -> %d\n", comms[0].c_str(), comms[1].c_str(), count);
            ans = min(ans, count);
        }
    }
    cout << ans << endl;
    return 0;
}
