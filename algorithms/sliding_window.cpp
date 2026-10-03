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

int longest_subarray_sum_leq_nonnegative(const vector<long long>& a, long long limit) {
    // Requires a[i] >= 0.
    int left=0, ans=0;
    long long sum=0;
    for(int right=0;right<(int)a.size();++right) {
        sum+=a[right];
        while(left<=right && sum>limit) sum-=a[left++];
        ans=max(ans,right-left+1);
    }
    return ans;
}
