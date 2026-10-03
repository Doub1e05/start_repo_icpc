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

int lis_length(const vector<long long>& a) {
    vector<long long> tails;
    for(long long x:a) {
        auto it=lower_bound(tails.begin(),tails.end(),x);
        if(it==tails.end()) tails.push_back(x); else *it=x;
    }
    return tails.size();
}
