#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
const int inf=1e9+4;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
int f(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> v(n+4);
    vector<pair<int, int>> v1(m+4);  
    unordered_map<pair<int, int>, vector<int>, pair_hash> d;
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < m; i++) cin >> v1[i].first >> v1[i].second;
    for (int i = 0; i < n; i++) {
        int x = v[i].first, y = v[i].second;
        if (x == 0) d[{inf, inf}].push_back(y);
        else {
            int g = f(x, y);
            d[{x / g, y / g}].push_back(x);
        }
    }
    for (auto& i : d) sort(i.second.begin(), i.second.end());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x = v1[i].first, y = v1[i].second;
        int xx, yy;
        if (x == 0) xx = inf, yy = inf;
        else {
            int g = f(x, y);
            xx = x / g, yy = y / g;
        }
        int val = !x ? y : x;
        if (d.find({xx, yy}) == d.end() || d[{xx, yy}].empty()) {continue;}
        auto& v2 = d[{xx, yy}];
        int t = 0;
        if(val>0){
            auto l = lower_bound(v2.begin(), v2.end(), 0);
            auto r = upper_bound(v2.begin(), v2.end(), val);
            t=distance(l,r);
        }
        else{
            auto l = upper_bound(v2.begin(), v2.end(), 0);
            auto r = lower_bound(v2.begin(), v2.end(), val);
            t=distance(r,l);
        }
        ans = max(ans, t);
    }
    cout << ans;
}