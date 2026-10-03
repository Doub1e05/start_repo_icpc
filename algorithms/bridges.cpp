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

vector<int> bridges(int n,const vector<pair<int,int>>& edges) {
    // Undirected multigraph; return bridge edge indices.
    vector<vector<pair<int,int>>> g(n);
    for(int id=0;id<(int)edges.size();++id) {
        auto [u,v]=edges[id]; g[u].push_back({v,id}); g[v].push_back({u,id});
    }
    vector<int> tin(n,-1),low(n),answer;
    int timer=0;
    for(int s=0;s<n;++s) if(tin[s]==-1) {
        vector<array<int,3>> st={{s,-1,0}};
        while(!st.empty()) {
            auto &[u,parent_edge,idx]=st.back();
            if(tin[u]==-1) tin[u]=low[u]=timer++;
            if(idx==(int)g[u].size()) {
                int done_u=u, done_edge=parent_edge;
                st.pop_back();
                if(!st.empty()) {
                    int p=st.back()[0]; low[p]=min(low[p],low[done_u]);
                    if(low[done_u]>tin[p]) answer.push_back(done_edge);
                }
                continue;
            }
            auto [v,id]=g[u][idx++];
            if(id==parent_edge) continue;
            if(tin[v]==-1) st.push_back({v,id,0});
            else low[u]=min(low[u],tin[v]);
        }
    }
    return answer;
}
