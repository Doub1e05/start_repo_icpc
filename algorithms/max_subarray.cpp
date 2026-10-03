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

long long max_subarray_sum(const vector<long long>& a) {
    // Nonempty subarray; a must be nonempty.
    long long best=a[0],current=a[0];
    for(int i=1;i<(int)a.size();++i) {
        current=max(a[i],current+a[i]); best=max(best,current);
    }
    return best;
}
