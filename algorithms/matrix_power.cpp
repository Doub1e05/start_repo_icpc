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

using Matrix=vector<vector<long long>>;
Matrix matrix_multiply(const Matrix& a,const Matrix& b,long long mod) {
    int n=a.size(); Matrix out(n,vector<long long>(n));
    for(int i=0;i<n;++i) for(int k=0;k<n;++k) if(a[i][k])
        for(int j=0;j<n;++j) out[i][j]=(out[i][j]+(__int128)a[i][k]*b[k][j])%mod;
    return out;
}
Matrix matrix_power(Matrix a,long long exponent,long long mod) {
    int n=a.size(); Matrix result(n,vector<long long>(n));
    for(int i=0;i<n;++i) result[i][i]=1%mod;
    while(exponent) {
        if(exponent&1) result=matrix_multiply(result,a,mod);
        a=matrix_multiply(a,a,mod); exponent>>=1;
    }
    return result;
}
