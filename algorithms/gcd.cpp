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

long long gcd_ll(long long a, long long b) {
    while (b) { long long t = a % b; a = b; b = t; }
    return a < 0 ? -a : a;
}
long long lcm_ll(long long a, long long b) {
    return a == 0 || b == 0 ? 0 : (a / gcd_ll(a, b) * b < 0 ? -(a / gcd_ll(a, b) * b) : a / gcd_ll(a, b) * b);
}
