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

#define INF 101
int main(void) {
    string str;
    cin >> str;
    int len = str.length();
    vector<int> map(26);
    for(int i = 0; i < len; i++) map[str[i]-'a']++;

    int ans = INF;
    for(int i = 0; i < 26; i++) {
        if(!map[i]) continue;
        // corner-case
        if(map[i] == len) { ans = 0; break; }
        char pivot = i + 'a';
        int cnt = 0;
        string prev = str;
        while(1) {
            cnt++;
            string cur;
            int is_ok = 1;
            for(int j = 0; j < prev.length()-1; j++) {
                char ch = prev[j];
                if(prev[j+1] == pivot) ch = prev[j+1];
                cur.push_back(ch);
                if(ch != pivot) is_ok = 0;
            }
            if(is_ok) break;
            debug("%s\n", cur.c_str());
            prev = cur;
        }
        debug("%c -> %d\n", pivot, cnt);
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
