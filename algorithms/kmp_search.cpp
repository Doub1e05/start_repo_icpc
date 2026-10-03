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

vector<int> kmp_search(const string& text,const string& pattern) {
    vector<int> ans;
    if(pattern.empty()) {
        for(int i=0;i<=(int)text.size();++i) ans.push_back(i);
        return ans;
    }
    vector<int> pi(pattern.size());
    for(int i=1;i<(int)pattern.size();++i) {
        int j=pi[i-1];
        while(j && pattern[i]!=pattern[j]) j=pi[j-1];
        if(pattern[i]==pattern[j]) ++j;
        pi[i]=j;
    }
    int j=0;
    for(int i=0;i<(int)text.size();++i) {
        while(j && text[i]!=pattern[j]) j=pi[j-1];
        if(text[i]==pattern[j]) ++j;
        if(j==(int)pattern.size()) { ans.push_back(i-j+1); j=pi[j-1]; }
    }
    return ans;
}
