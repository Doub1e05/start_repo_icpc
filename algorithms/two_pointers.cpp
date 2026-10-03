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

long long count_pairs_sum_leq(const vector<long long>& a, long long limit) {
    // a must be sorted; pairs i < j.
    int l=0, r=(int)a.size()-1;
    long long ans=0;
    while(l<r) {
        if(a[l]+a[r]<=limit) { ans+=r-l; ++l; }
        else --r;
    }
    return ans;
}
