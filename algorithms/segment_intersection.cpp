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
__int128 cross(Point a,Point b,Point c) {
    return (__int128)(b.first-a.first)*(c.second-a.second)
         - (__int128)(b.second-a.second)*(c.first-a.first);
}
bool on_segment(Point a,Point b,Point p) {
    return min(a.first,b.first)<=p.first && p.first<=max(a.first,b.first)
        && min(a.second,b.second)<=p.second && p.second<=max(a.second,b.second);
}
bool segments_intersect(Point a,Point b,Point c,Point d) {
    auto x1=cross(a,b,c),x2=cross(a,b,d),y1=cross(c,d,a),y2=cross(c,d,b);
    if((x1==0 && on_segment(a,b,c)) || (x2==0 && on_segment(a,b,d))) return true;
    if((y1==0 && on_segment(c,d,a)) || (y2==0 && on_segment(c,d,b))) return true;
    return ((x1<0 && x2>0)||(x1>0 && x2<0)) && ((y1<0 && y2>0)||(y1>0 && y2<0));
}
