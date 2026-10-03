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

struct SegmentTree {
    int n, size;
    vector<long long> tree;
    explicit SegmentTree(const vector<long long>& a): n(a.size()), size(1) {
        while(size<n) size*=2;
        tree.assign(2*size,0);
        for(int i=0;i<n;++i) tree[size+i]=a[i];
        for(int i=size-1;i>=1;--i) tree[i]=tree[2*i]+tree[2*i+1];
    }
    void set(int index,long long value) {
        int i=size+index; tree[i]=value;
        while(i>1) { i/=2; tree[i]=tree[2*i]+tree[2*i+1]; }
    }
    long long query(int left,int right) const {
        long long ans=0;
        for(left+=size,right+=size;left<right;left/=2,right/=2) {
            if(left&1) ans+=tree[left++];
            if(right&1) ans+=tree[--right];
        }
        return ans;
    }
};
