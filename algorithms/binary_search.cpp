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

template<class Predicate>
long long first_true(long long lo, long long hi, Predicate pred) {
    // [lo, hi): false then true; returns hi if none.
    while(lo<hi) {
        long long mid=lo+(hi-lo)/2;
        if(pred(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}
