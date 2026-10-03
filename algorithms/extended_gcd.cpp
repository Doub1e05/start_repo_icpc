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

tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    long long old_r=a, r=b, old_x=1, x=0, old_y=0, y=1;
    while (r) {
        long long q=old_r/r;
        tie(old_r,r)=make_pair(r,old_r-q*r);
        tie(old_x,x)=make_pair(x,old_x-q*x);
        tie(old_y,y)=make_pair(y,old_y-q*y);
    }
    if (old_r<0) return {-old_r,-old_x,-old_y};
    return {old_r,old_x,old_y};
}
long long mod_inverse(long long a, long long mod) {
    auto [g,x,y]=extended_gcd(a,mod);
    if (g!=1) throw invalid_argument("inverse does not exist");
    return (x%mod+mod)%mod;
}
