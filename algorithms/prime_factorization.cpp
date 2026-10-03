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

vector<pair<long long,int>> factorize(long long n) {
    if (n<1) throw invalid_argument("n must be positive");
    vector<pair<long long,int>> out;
    for (long long p=2; p<=n/p; p+=(p==2?1:2)) {
        if (n%p==0) {
            int e=0;
            do { n/=p; ++e; } while (n%p==0);
            out.push_back({p,e});
        }
    }
    if (n>1) out.push_back({n,1});
    return out;
}
