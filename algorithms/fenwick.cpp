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

struct Fenwick {
    int n;
    vector<long long> bit;
    explicit Fenwick(int n): n(n), bit(n+1,0) {}
    void add(int index,long long delta) {
        for(++index;index<=n;index+=index&-index) bit[index]+=delta;
    }
    long long prefix_sum(int end) const {
        long long ans=0;
        for(;end>0;end-=end&-end) ans+=bit[end];
        return ans;
    }
    long long sum_range(int left,int right) const { return prefix_sum(right)-prefix_sum(left); }
};
