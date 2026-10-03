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

vector<long long> apply_range_add(vector<long long> a,const vector<tuple<int,int,long long>>& updates) {
    vector<long long> diff(a.size()+1,0);
    for(auto [left,right,delta]:updates) { diff[left]+=delta; diff[right]-=delta; }
    long long running=0;
    for(int i=0;i<(int)a.size();++i) { running+=diff[i]; a[i]+=running; }
    return a;
}
