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

pair<long long,long long> crt_pair(long long a,long long m,long long b,long long n) {
    // Returns {x,lcm} or {-1,-1} if inconsistent; requires m,n > 0.
    function<tuple<long long,long long,long long>(long long,long long)> egcd =
        [&](long long x,long long y)->tuple<long long,long long,long long> {
            if(y==0) return {x,1,0};
            auto [g,p,q]=egcd(y,x%y);
            return {g,q,p-(x/y)*q};
        };
    auto [g,inverse,unused]=egcd(m,n);
    if((b-a)%g) return {-1,-1};
    long long modulus=m/g*n;
    long long step=((__int128)(b-a)/g*inverse%(n/g)+(n/g))%(n/g);
    long long x=((__int128)a+(__int128)m*step)%modulus;
    if(x<0) x+=modulus;
    return {x,modulus};
}
