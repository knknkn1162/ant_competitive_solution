#include <vector>
#include <utility> // pair, make_pair
using namespace std;
typedef pair<int,int> pii;
#define DIVISOR 1000000007




pii gcdext(int a, int b) {
    if(a==0) { return make_pair(0,1); }
    pii p = gcdext(b%a, a);
    return make_pair(p.second - (b/a)*p.first, p.first);
}

static vector<int64_t> factorial;
static vector<int64_t> inv_factorial;

void init_factorial(int size) {
    factorial.resize(size+1);
    inv_factorial.resize(size+1);
    factorial[0] = factorial[1] = 1;
    inv_factorial[0] = inv_factorial[1] = 1;

    for(int i = 2; i <= size; i++) {
        factorial[i] = (factorial[i-1] * i)%DIVISOR;
        pii p = gcdext(i, DIVISOR);
        int inv = (p.first + DIVISOR)%DIVISOR;
        inv_factorial[i] = (inv_factorial[i-1] * inv)%DIVISOR;
    }
    return;
}

int64_t calc_npk(int n, int k) {
    if(k > n) return 0;
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    // ans = (ans * inv_factorial[k])%DIVISOR;
    return ans;
}

int64_t calc_nck(int n, int k) {
    if(k > n) return 0;
    int64_t ans = 1;
    ans = (ans * factorial[n])%DIVISOR;
    ans = (ans * inv_factorial[n-k])%DIVISOR;
    ans = (ans * inv_factorial[k])%DIVISOR;
    return ans;
}
