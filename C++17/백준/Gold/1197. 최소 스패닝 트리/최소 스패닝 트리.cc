#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int d[10001]; 
vector<pair<pair<int, int>, int>> v;
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}
int f(int x) {
    if (d[x] == x) return x;
    return d[x] = f(d[x]);
}
void g(int x, int y) {
    int X = f(x), Y = f(y);
    if (X != Y) d[X] = Y;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) d[i] = i;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        v.push_back({ {x, y}, z });
    }
    sort(v.begin(), v.end(), compare);
    int ans = 0;
    for (auto i : v) {
        int x = i.first.first, y = i.first.second, w = i.second;
        if (f(x) != f(y)) {
            g(x, y);
            ans += w;
        }
    }
    cout << ans;
}