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

bool subset_sum_possible(const vector<int>& values,int target) {
    // values >= 0; O(n * target) time, O(target) memory.
    vector<char> possible(target+1,false);
    possible[0]=true;
    for(int x:values) for(int sum=target;sum>=x;--sum)
        if(possible[sum-x]) possible[sum]=true;
    return possible[target];
}
