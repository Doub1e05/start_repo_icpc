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

vector<pair<int,int>> bipartite_matching(const vector<vector<int>>& g,int right_size) {
    vector<int> match(right_size,-1);
    int n=g.size();
    for(int start=0;start<n;++start) {
        vector<char> seen(n,false);
        vector<int> parent_u(n,-1),parent_v(n,-1);
        vector<pair<int,int>> st={{start,0}}; seen[start]=true;
        bool done=false;
        while(!st.empty() && !done) {
            int u=st.back().first, &idx=st.back().second;
            if(idx==(int)g[u].size()) { st.pop_back(); continue; }
            int v=g[u][idx++], matched=match[v];
            if(matched==-1) {
                while(true) {
                    match[v]=u;
                    if(u==start) break;
                    int old_u=u; u=parent_u[old_u]; v=parent_v[old_u];
                }
                done=true;
            } else if(!seen[matched]) {
                seen[matched]=true; parent_u[matched]=u; parent_v[matched]=v;
                st.push_back({matched,0});
            }
        }
    }
    vector<pair<int,int>> result;
    for(int v=0;v<right_size;++v) if(match[v]!=-1) result.push_back({match[v],v});
    return result;
}
