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

struct Trie {
    struct Node { array<int,26> next; bool terminal=false; Node() { next.fill(-1); } };
    vector<Node> nodes={Node()};
    void insert(const string& word) {
        int u=0;
        for(char ch:word) {
            int c=ch-'a';
            if(nodes[u].next[c]==-1) {
                nodes[u].next[c]=nodes.size(); nodes.emplace_back();
            }
            u=nodes[u].next[c];
        }
        nodes[u].terminal=true;
    }
    bool contains(const string& word) const {
        int u=0;
        for(char ch:word) {
            int c=ch-'a';
            if(nodes[u].next[c]==-1) return false;
            u=nodes[u].next[c];
        }
        return nodes[u].terminal;
    }
};
