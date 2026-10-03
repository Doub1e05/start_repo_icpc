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

vector<int> bfs(const vector<vector<int>>& graph,int source) {
    vector<int> dist(graph.size(),-1);
    queue<int> q;
    dist[source]=0; q.push(source);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int v:graph[u]) if(dist[v]==-1) { dist[v]=dist[u]+1; q.push(v); }
    }
    return dist;
}
