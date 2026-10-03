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

vector<int> dfs_order(const vector<vector<int>>& graph,int source) {
    vector<char> seen(graph.size(),false);
    vector<int> order, stack={source};
    while(!stack.empty()) {
        int u=stack.back(); stack.pop_back();
        if(seen[u]) continue;
        seen[u]=true; order.push_back(u);
        for(auto it=graph[u].rbegin();it!=graph[u].rend();++it) stack.push_back(*it);
    }
    return order;
}
