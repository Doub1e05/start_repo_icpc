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

vector<vector<int>> strongly_connected_components(const vector<vector<int>>& g) {
    int n=g.size();
    vector<vector<int>> rev(n), components;
    for(int u=0;u<n;++u) for(int v:g[u]) rev[v].push_back(u);
    vector<char> seen(n,false);
    vector<int> order;
    for(int s=0;s<n;++s) if(!seen[s]) {
        vector<pair<int,int>> st={{s,0}}; seen[s]=true;
        while(!st.empty()) {
            int u=st.back().first, &idx=st.back().second;
            if(idx==(int)g[u].size()) { order.push_back(u); st.pop_back(); }
            else { int v=g[u][idx++]; if(!seen[v]) { seen[v]=true; st.push_back({v,0}); } }
        }
    }
    fill(seen.begin(),seen.end(),false);
    for(auto it=order.rbegin();it!=order.rend();++it) if(!seen[*it]) {
        vector<int> comp,st={*it}; seen[*it]=true;
        while(!st.empty()) {
            int u=st.back(); st.pop_back(); comp.push_back(u);
            for(int v:rev[u]) if(!seen[v]) { seen[v]=true; st.push_back(v); }
        }
        components.push_back(std::move(comp));
    }
    return components;
}
