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

vector<int> directed_eulerian_path(int n,const vector<pair<int,int>>& edges) {
    if(n==0) return {};
    vector<vector<int>> g(n);
    vector<int> in(n),out(n);
    for(auto [u,v]:edges) { g[u].push_back(v); ++out[u]; ++in[v]; }
    int starts=0,ends=0,start=0;
    for(int i=0;i<n;++i) {
        int diff=out[i]-in[i];
        if(abs(diff)>1) return {};
        if(diff==1) { ++starts; start=i; }
        if(diff==-1) ++ends;
    }
    if(starts!=ends || starts>1) return {};
    if(!starts) for(int i=0;i<n;++i) if(out[i]) { start=i; break; }
    vector<int> stack={start},path;
    while(!stack.empty()) {
        int u=stack.back();
        if(!g[u].empty()) { stack.push_back(g[u].back()); g[u].pop_back(); }
        else { path.push_back(u); stack.pop_back(); }
    }
    reverse(path.begin(),path.end());
    return path.size()==edges.size()+1 ? path : vector<int>{};
}
