#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int d[104];
vector<pair<double, double>> v;
vector<pair<double, pair<int, int>>> v1;
int f(int x) {
    if (x == d[x]) return x;
    return d[x] = f(d[x]);
}
void g(int x, int y) {
    x = f(x), y = f(y);
    if (x != y) d[x] = y;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) d[i] = i;
    for (int i = 0; i < n; i++) {
        double x,y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            double x = (v[i].first - v[j].first) * (v[i].first - v[j].first);
            double y = (v[i].second - v[j].second) * (v[i].second - v[j].second);
            v1.push_back({ sqrt(x + y), { i, j } });
        }
    }
    double ans = 0;
    sort(v1.begin(), v1.end());
    for (auto i : v1) {
        int x = i.second.first, y = i.second.second;
        double z = i.first;
        if (f(x) != f(y)) {
            g(x, y);
            ans += z;
        }
    }
    cout << fixed << setprecision(2) << ans;
}