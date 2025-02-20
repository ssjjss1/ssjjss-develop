#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
using Point = pair<ll, ll>;
int n;
ll ccw(Point a, Point b, Point c) {
    ll res = (b.first - a.first) * (c.second - b.second) - (c.first - b.first) * (b.second - a.second);
    return (res > 0) - (res < 0);
}
ll Dist(Point p1, Point p2) {
    ll dx = p2.first - p1.first, dy = p2.second - p1.second;
    return dx * dx + dy * dy;
}
vector<Point> ConvexHull(vector<Point> points) {
    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), [&](auto a, auto b) {
        int dir = ccw(points[0], a, b);
        if (dir != 0) return dir > 0;
        return Dist(points[0], a) < Dist(points[0], b);
    });
    vector<Point> stk;
    for (auto i : points) {
        while (stk.size() >= 2 && ccw(stk[stk.size() - 2], stk.back(), i) <= 0) {
            stk.pop_back();
        }
        stk.push_back(i);
    }
    return stk;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<Point> v; 
    for (ll i = 0, x, y; i < n; i++) {  
        cin >> x >> y;
        v.push_back({x, y});
    }
    vector<Point> v1 = ConvexHull(v);
    cout << v1.size();
}