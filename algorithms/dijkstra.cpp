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

vector<long long> dijkstra(const vector<vector<pair<int,long long>>>& graph,int source) {
    const long long INF=numeric_limits<long long>::max()/4;
    vector<long long> dist(graph.size(),INF);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    dist[source]=0; pq.push({0,source});
    while(!pq.empty()) {
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]:graph[u]) if(d+w<dist[v]) {
            dist[v]=d+w; pq.push({dist[v],v});
        }
    }
    return dist;
}
