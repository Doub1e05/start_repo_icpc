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

struct LCA {
    vector<int> depth;
    vector<vector<int>> up;
    explicit LCA(const vector<vector<int>>& g,int root=0): depth(g.size(),-1) {
        int n=g.size(), levels=1;
        while((1LL<<levels)<=n) ++levels;
        up.assign(levels,vector<int>(n,root));
        vector<int> st={root}; depth[root]=0;
        while(!st.empty()) {
            int u=st.back(); st.pop_back();
            for(int v:g[u]) if(depth[v]==-1) {
                depth[v]=depth[u]+1; up[0][v]=u; st.push_back(v);
            }
        }
        for(int k=1;k<levels;++k) for(int v=0;v<n;++v) up[k][v]=up[k-1][up[k-1][v]];
    }
    int query(int a,int b) const {
        if(depth[a]<depth[b]) swap(a,b);
        int diff=depth[a]-depth[b];
        for(int k=0;k<(int)up.size();++k) if(diff>>k&1) a=up[k][a];
        if(a==b) return a;
        for(int k=(int)up.size()-1;k>=0;--k) if(up[k][a]!=up[k][b]) {
            a=up[k][a]; b=up[k][b];
        }
        return up[0][a];
    }
};
