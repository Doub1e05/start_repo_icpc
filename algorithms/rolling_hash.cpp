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

struct RollingHash {
    static constexpr long long MOD=1000000007, BASE=911382323;
    vector<long long> power,prefix;
    explicit RollingHash(const string& s): power(s.size()+1,1),prefix(s.size()+1,0) {
        for(int i=0;i<(int)s.size();++i) {
            power[i+1]=power[i]*BASE%MOD;
            prefix[i+1]=(prefix[i]*BASE+(unsigned char)s[i]+1)%MOD;
        }
    }
    long long hash(int left,int right) const {
        return (prefix[right]-prefix[left]*power[right-left]%MOD+MOD)%MOD;
    }
};
