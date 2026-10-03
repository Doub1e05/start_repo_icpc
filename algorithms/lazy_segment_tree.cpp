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

struct LazySegmentTree {
    int n;
    vector<long long> tree,lazy;
    explicit LazySegmentTree(const vector<long long>& a): n(a.size()),tree(4*max(1,n)),lazy(4*max(1,n)) {
        if(n) build(1,0,n,a);
    }
    void build(int u,int l,int r,const vector<long long>& a) {
        if(r-l==1) { tree[u]=a[l]; return; }
        int m=(l+r)/2; build(2*u,l,m,a); build(2*u+1,m,r,a);
        tree[u]=tree[2*u]+tree[2*u+1];
    }
    void apply(int u,int len,long long delta) { tree[u]+=delta*len; lazy[u]+=delta; }
    void push(int u,int l,int r) {
        if(lazy[u] && r-l>1) {
            int m=(l+r)/2;
            apply(2*u,m-l,lazy[u]); apply(2*u+1,r-m,lazy[u]); lazy[u]=0;
        }
    }
    void add(int ql,int qr,long long delta) { if(n) add(1,0,n,ql,qr,delta); }
    void add(int u,int l,int r,int ql,int qr,long long delta) {
        if(qr<=l || r<=ql) return;
        if(ql<=l && r<=qr) { apply(u,r-l,delta); return; }
        push(u,l,r); int m=(l+r)/2;
        add(2*u,l,m,ql,qr,delta); add(2*u+1,m,r,ql,qr,delta);
        tree[u]=tree[2*u]+tree[2*u+1];
    }
    long long query(int ql,int qr) { return n?query(1,0,n,ql,qr):0; }
    long long query(int u,int l,int r,int ql,int qr) {
        if(qr<=l || r<=ql) return 0;
        if(ql<=l && r<=qr) return tree[u];
        push(u,l,r); int m=(l+r)/2;
        return query(2*u,l,m,ql,qr)+query(2*u+1,m,r,ql,qr);
    }
};
