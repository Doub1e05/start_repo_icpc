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

long long tsp_cycle(const vector<vector<long long>>& cost) {
    int n=cost.size();
    const long long INF=numeric_limits<long long>::max()/4;
    vector<vector<long long>> dp(1<<n,vector<long long>(n,INF));
    dp[1][0]=0;
    for(int mask=1;mask<(1<<n);++mask) for(int u=0;u<n;++u) if(dp[mask][u]!=INF)
        for(int v=0;v<n;++v) if(!(mask>>v&1))
            dp[mask|1<<v][v]=min(dp[mask|1<<v][v],dp[mask][u]+cost[u][v]);
    long long ans=INF;
    for(int u=0;u<n;++u) ans=min(ans,dp[(1<<n)-1][u]+cost[u][0]);
    return ans;
}
