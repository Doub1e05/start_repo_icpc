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

struct SparseTableMin {
    vector<vector<long long>> st;
    explicit SparseTableMin(const vector<long long>& a) {
        if(a.empty()) throw invalid_argument("values must be nonempty");
        st.push_back(a);
        for(int len=1;2*len<=(int)a.size();len*=2) {
            vector<long long> row(a.size()-2*len+1);
            for(int i=0;i<(int)row.size();++i) row[i]=min(st.back()[i],st.back()[i+len]);
            st.push_back(std::move(row));
        }
    }
    long long query(int left,int right) const {
        int k=31-__builtin_clz(right-left);
        return min(st[k][left],st[k][right-(1<<k)]);
    }
};
