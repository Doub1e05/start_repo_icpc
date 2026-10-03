#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Combinations {
    long long mod;
    vector<long long> fact, inv_fact;
    static long long power(long long a, long long e, long long mod) {
        long long r=1;
        while(e) { if(e&1) r=(__int128)r*a%mod; a=(__int128)a*a%mod; e>>=1; }
        return r;
    }
    // mod is prime and max_n < mod.
    Combinations(int max_n, long long mod): mod(mod), fact(max_n+1,1), inv_fact(max_n+1,1) {
        if (max_n>=mod) throw invalid_argument("requires max_n < mod");
        for(int i=1;i<=max_n;++i) fact[i]=fact[i-1]*i%mod;
        inv_fact[max_n]=power(fact[max_n],mod-2,mod);
        for(int i=max_n;i>=1;--i) inv_fact[i-1]=inv_fact[i]*i%mod;
    }
    long long ncr(int n,int r) const {
        if(r<0 || r>n) return 0;
        return fact[n]*inv_fact[r]%mod*inv_fact[n-r]%mod;
    }
};
