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

vector<int> bipartite_coloring(const vector<vector<int>>& g) {
    // Undirected graph; colors 0/1 or empty if not bipartite.
    vector<int> color(g.size(),-1);
    for(int start=0;start<(int)g.size();++start) if(color[start]==-1) {
        queue<int> q; q.push(start); color[start]=0;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            for(int v:g[u]) {
                if(color[v]==-1) { color[v]=color[u]^1; q.push(v); }
                else if(color[v]==color[u]) return {};
            }
        }
    }
    return color;
}
