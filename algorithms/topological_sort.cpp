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

vector<int> topological_sort(const vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> indegree(n,0), order;
    for(const auto& adj:graph) for(int v:adj) ++indegree[v];
    queue<int> q;
    for(int i=0;i<n;++i) if(!indegree[i]) q.push(i);
    while(!q.empty()) {
        int u=q.front(); q.pop(); order.push_back(u);
        for(int v:graph[u]) if(--indegree[v]==0) q.push(v);
    }
    return (int)order.size()==n ? order : vector<int>{};
}
