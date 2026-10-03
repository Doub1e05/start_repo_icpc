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

vector<int> articulation_points(int n,const vector<pair<int,int>>& edges) {
    vector<vector<pair<int,int>>> g(n);
    for(int id=0;id<(int)edges.size();++id) {
        auto [u,v]=edges[id]; g[u].push_back({v,id}); g[v].push_back({u,id});
    }
    vector<int> tin(n,-1),low(n),children(n,0),answer;
    vector<char> is_art(n,false);
    int timer=0;
    for(int root=0;root<n;++root) if(tin[root]==-1) {
        vector<array<int,3>> st={{root,-1,0}};
        while(!st.empty()) {
            auto &[u,parent_edge,idx]=st.back();
            if(tin[u]==-1) tin[u]=low[u]=timer++;
            if(idx==(int)g[u].size()) {
                int done=u; st.pop_back();
                if(!st.empty()) {
                    int p=st.back()[0]; low[p]=min(low[p],low[done]);
                    if(st.back()[1]!=-1 && low[done]>=tin[p]) is_art[p]=true;
                }
                continue;
            }
            auto [v,id]=g[u][idx++];
            if(id==parent_edge) continue;
            if(tin[v]==-1) { ++children[u]; st.push_back({v,id,0}); }
            else low[u]=min(low[u],tin[v]);
        }
        if(children[root]>1) is_art[root]=true;
    }
    for(int i=0;i<n;++i) if(is_art[i]) answer.push_back(i);
    return answer;
}
