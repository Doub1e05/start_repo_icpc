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

struct PrefixSum2D {
    vector<vector<long long>> p;
    explicit PrefixSum2D(const vector<vector<long long>>& a) {
        int rows=a.size(),cols=rows?a[0].size():0;
        p.assign(rows+1,vector<long long>(cols+1,0));
        for(int r=0;r<rows;++r) for(int c=0;c<cols;++c)
            p[r+1][c+1]=a[r][c]+p[r][c+1]+p[r+1][c]-p[r][c];
    }
    long long query(int r1,int c1,int r2,int c2) const {
        return p[r2][c2]-p[r1][c2]-p[r2][c1]+p[r1][c1];
    }
};
