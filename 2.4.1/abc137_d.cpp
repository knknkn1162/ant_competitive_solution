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

template<typename T>
void p(T elem) {cout << elem << endl;}
template<typename T>
void ps(vector<T>& arr) { for(T e: arr) p(e); }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

struct job {
    int days;
    int fee;
};

int main(void) {
    int num, dlimit;
    cin >> num >> dlimit;
    vector<struct job> jobs(num);
    for(auto& job: jobs) {
        cin >> job.days >> job.fee;
    }
    auto comp = [](struct job j1, struct job j2) {
        return j1.days < j2.days;
    };
    sort(jobs.begin(), jobs.end(), comp);

    int ans = 0;
    int j = 0;
    priority_queue<int, std::vector<int>> max_queue;
    for(int m = dlimit-1; m >= 0; m--) {
        for(; j < num; j++) {
            struct job job = jobs[j];
            if(job.days > dlimit-m) break;
            max_queue.push(job.fee);
        }
        if(max_queue.empty()) continue;
        ans += max_queue.top();
        max_queue.pop();
    }
    cout << ans << endl;
    return 0;
}
