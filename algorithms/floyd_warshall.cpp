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

vector<vector<long long>> floyd_warshall(vector<vector<long long>> d) {
    const long long INF=numeric_limits<long long>::max()/4;
    int n=d.size();
    for(int k=0;k<n;++k) for(int i=0;i<n;++i) if(d[i][k]!=INF)
        for(int j=0;j<n;++j) if(d[k][j]!=INF)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    return d;
}
