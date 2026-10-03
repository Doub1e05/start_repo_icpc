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

pair<vector<long long>,bool> bellman_ford(int n,const vector<tuple<int,int,long long>>& edges,int source) {
    const long long INF=numeric_limits<long long>::max()/4;
    vector<long long> dist(n,INF); dist[source]=0;
    for(int i=0;i<n-1;++i) {
        bool changed=false;
        for(auto [u,v,w]:edges) if(dist[u]!=INF && dist[u]+w<dist[v]) {
            dist[v]=dist[u]+w; changed=true;
        }
        if(!changed) break;
    }
    for(auto [u,v,w]:edges) if(dist[u]!=INF && dist[u]+w<dist[v]) return {dist,true};
    return {dist,false};
}
