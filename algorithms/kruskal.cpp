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

pair<long long,vector<tuple<long long,int,int>>> kruskal(int n,vector<tuple<long long,int,int>> edges) {
    // Undirected edges (weight,u,v); returns forest if disconnected.
    sort(edges.begin(),edges.end());
    vector<int> p(n),sz(n,1); iota(p.begin(),p.end(),0);
    auto find=[&](int x) { while(p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x; };
    long long total=0;
    vector<tuple<long long,int,int>> chosen;
    for(auto [w,u,v]:edges) {
        int a=find(u),b=find(v);
        if(a==b) continue;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; total+=w; chosen.push_back({w,u,v});
    }
    return {total,chosen};
}
