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

vector<long long> zero_one_bfs(const vector<vector<pair<int,int>>>& graph,int source) {
    const long long INF=numeric_limits<long long>::max()/4;
    vector<long long> dist(graph.size(),INF);
    deque<int> q; q.push_back(source); dist[source]=0;
    while(!q.empty()) {
        int u=q.front(); q.pop_front();
        for(auto [v,w]:graph[u]) if(dist[u]+w<dist[v]) {
            dist[v]=dist[u]+w;
            if(w==0) q.push_front(v); else q.push_back(v);
        }
    }
    return dist;
}
