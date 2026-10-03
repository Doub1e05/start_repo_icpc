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

pair<vector<int>,vector<long long>> compress(const vector<long long>& a) {
    vector<long long> unique=a;
    sort(unique.begin(),unique.end());
    unique.erase(std::unique(unique.begin(),unique.end()),unique.end());
    vector<int> rank;
    for(long long x:a) rank.push_back(lower_bound(unique.begin(),unique.end(),x)-unique.begin());
    return {rank,unique};
}
