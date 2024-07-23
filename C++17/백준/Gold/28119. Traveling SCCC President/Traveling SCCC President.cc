#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k;
int d[300004];
vector<pair<pair<int, int>, int>> v;
vector<int> v1;
bool compare(pair<pair<int, int>, int> &x, pair<pair<int, int>, int> &y) {
    return x.second < y.second;
}
int f(int x) {
    if (x == d[x]) return x;
    return d[x] = f(d[x]);
}
void g(int x, int y) {
    int X = f(x), Y = f(y);
    if (X != Y) d[X] = Y;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) d[i] = i;
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        v.push_back({{x, y}, z});
    }
    v1.resize(n + 1); 
    for (int i = 1; i <= n; i++) cin >> v1[i];
    int ans = 0;
    sort(v.begin(), v.end(), compare);
    for (auto i : v) {
        int x = i.first.first, y = i.first.second, w = i.second;
        if (f(x) != f(y)) {
            g(x, y);
            ans += w;
        }
    }
    cout << ans;
}