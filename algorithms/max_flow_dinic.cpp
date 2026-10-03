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

struct Dinic {
    struct Edge { int to, rev; long long cap; };
    vector<vector<Edge>> g;
    explicit Dinic(int n): g(n) {}
    void add_edge(int u,int v,long long cap) {
        int ui=g[u].size(), vi=g[v].size();
        g[u].push_back({v,vi+(u==v),cap});
        g[v].push_back({u,ui,0});
    }
    long long max_flow(int source,int sink) {
        if(source==sink) return 0;
        int n=g.size(); long long flow=0;
        while(true) {
            vector<int> level(n,-1),ptr(n,0);
            queue<int> q; q.push(source); level[source]=0;
            while(!q.empty()) {
                int u=q.front(); q.pop();
                for(const auto& e:g[u]) if(e.cap>0 && level[e.to]==-1) {
                    level[e.to]=level[u]+1; q.push(e.to);
                }
            }
            if(level[sink]==-1) return flow;
            function<long long(int,long long)> send=[&](int u,long long pushed) -> long long {
                if(u==sink) return pushed;
                for(int &i=ptr[u];i<(int)g[u].size();++i) {
                    Edge &e=g[u][i];
                    if(e.cap<=0 || level[e.to]!=level[u]+1) continue;
                    long long got=send(e.to,min(pushed,e.cap));
                    if(got) { e.cap-=got; g[e.to][e.rev].cap+=got; return got; }
                }
                return 0;
            };
            while(long long pushed=send(source,numeric_limits<long long>::max()/4)) flow+=pushed;
        }
    }
};
