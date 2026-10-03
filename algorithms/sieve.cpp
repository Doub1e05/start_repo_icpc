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

vector<int> sieve(int n) {
    if (n<2) return {};
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int p=2; (long long)p*p<=n; ++p)
        if (prime[p]) for (int x=p*p; x<=n; x+=p) prime[x]=false;
    vector<int> out;
    for (int i=2;i<=n;++i) if (prime[i]) out.push_back(i);
    return out;
}
