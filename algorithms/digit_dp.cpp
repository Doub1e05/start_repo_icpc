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

long long count_without_adjacent_equal(long long n) {
    if(n<0) return 0;
    string digits=to_string(n);
    long long memo[20][11][2][2];
    for(auto &a:memo) for(auto &b:a) for(auto &c:b) for(auto &d:c) d=-1;
    function<long long(int,int,int,int)> dp=[&](int pos,int prev,int tight,int started)->long long {
        if(pos==(int)digits.size()) return 1;
        long long &ans=memo[pos][prev][tight][started];
        if(ans!=-1) return ans;
        ans=0; int upper=tight?digits[pos]-'0':9;
        for(int digit=0;digit<=upper;++digit) {
            int next_started=started || digit!=0;
            if(started && digit==prev) continue;
            ans+=dp(pos+1,next_started?digit:10,tight && digit==upper,next_started);
        }
        return ans;
    };
    return dp(0,10,1,0);
}
