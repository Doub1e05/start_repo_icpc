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

struct PrefixSum {
    vector<long long> pref={0};
    explicit PrefixSum(const vector<long long>& a) {
        for(long long x:a) pref.push_back(pref.back()+x);
    }
    long long query(int left,int right) const { return pref[right]-pref[left]; }
};
