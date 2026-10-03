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

long long mod_pow(long long a, long long exp, long long mod) {
    if (exp<0 || mod<=0) throw invalid_argument("need exp >= 0 and mod > 0");
    long long ans=1%mod;
    a=(a%mod+mod)%mod;
    while (exp) {
        if (exp&1) ans=(__int128)ans*a%mod;
        a=(__int128)a*a%mod;
        exp>>=1;
    }
    return ans;
}
