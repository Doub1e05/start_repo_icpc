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

using Point=pair<long long,long long>;
__int128 cross(Point o,Point a,Point b) {
    return (__int128)(a.first-o.first)*(b.second-o.second)
         - (__int128)(a.second-o.second)*(b.first-o.first);
}
vector<Point> convex_hull(vector<Point> points) {
    sort(points.begin(),points.end());
    points.erase(unique(points.begin(),points.end()),points.end());
    if(points.size()<=1) return points;
    vector<Point> lower,upper;
    for(Point p:points) {
        while(lower.size()>=2 && cross(lower[lower.size()-2],lower.back(),p)<=0) lower.pop_back();
        lower.push_back(p);
    }
    for(auto it=points.rbegin();it!=points.rend();++it) {
        while(upper.size()>=2 && cross(upper[upper.size()-2],upper.back(),*it)<=0) upper.pop_back();
        upper.push_back(*it);
    }
    lower.pop_back(); upper.pop_back();
    lower.insert(lower.end(),upper.begin(),upper.end());
    return lower;
}
