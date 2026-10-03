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

vector<long long> aho_count(const string& text,const vector<string>& patterns) {
    // Lowercase a-z; patterns nonempty. Count occurrences of each pattern.
    struct Node { array<int,26> next; int link=0; Node() { next.fill(-1); } };
    vector<Node> nodes(1);
    vector<int> terminal;
    for(const string& pattern:patterns) {
        int u=0;
        for(char ch:pattern) {
            int c=ch-'a';
            if(nodes[u].next[c]==-1) { nodes[u].next[c]=nodes.size(); nodes.emplace_back(); }
            u=nodes[u].next[c];
        }
        terminal.push_back(u);
    }
    queue<int> q;
    for(int c=0;c<26;++c) {
        int v=nodes[0].next[c];
        if(v==-1) nodes[0].next[c]=0; else q.push(v);
    }
    vector<int> order;
    while(!q.empty()) {
        int u=q.front(); q.pop(); order.push_back(u);
        for(int c=0;c<26;++c) {
            int v=nodes[u].next[c];
            if(v==-1) nodes[u].next[c]=nodes[nodes[u].link].next[c];
            else { nodes[v].link=nodes[nodes[u].link].next[c]; q.push(v); }
        }
    }
    vector<long long> count(nodes.size(),0);
    int u=0;
    for(char ch:text) { u=nodes[u].next[ch-'a']; ++count[u]; }
    for(auto it=order.rbegin();it!=order.rend();++it) count[nodes[*it].link]+=count[*it];
    vector<long long> result;
    for(int v:terminal) result.push_back(count[v]);
    return result;
}
