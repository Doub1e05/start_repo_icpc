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

long long knapsack_01(const vector<pair<int,long long>>& items,int capacity) {
    vector<long long> dp(capacity+1,0);
    for(auto [weight,value]:items)
        for(int c=capacity;c>=weight;--c) dp[c]=max(dp[c],dp[c-weight]+value);
    return dp[capacity];
}
