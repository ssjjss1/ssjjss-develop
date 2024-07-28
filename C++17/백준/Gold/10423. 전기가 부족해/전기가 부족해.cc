#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, ans;
int d[1004], a[1004];
vector<pair<pair<int, int>, int>> v;
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}
int f(int x) {
    if (x == d[x]) return x;
    return d[x] = f(d[x]);
}
void g(int x, int y) {
    if (x != y) d[x] = y;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) d[i] = i;
    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        v.push_back({ {x, y}, z });
    }
    sort(v.begin(), v.end(), compare);
    for (auto i : v) {
        int x = i.first.first, y = i.first.second, w = i.second;
        if (a[x] && a[y]) continue; 
        int X = f(x), Y = f(y);
        if (X != Y) {
            if ((a[X] && a[Y])) continue;
            if(a[X]) g(Y,X);
            else g(X,Y); 
            ans += w;
        }
    }
    cout << ans ;
}