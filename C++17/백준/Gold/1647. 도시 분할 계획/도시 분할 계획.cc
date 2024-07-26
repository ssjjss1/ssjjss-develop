#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll a[100004];
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}
int f(int x) {
    if (a[x] == x) return x;
    return a[x] = f(a[x]);
}
void g(int x, int y) {
    int X = f(x), Y = f(y);
    if (X != Y) a[X] = Y;
}
vector<pair<pair<int, int>, int>> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n>>m;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1,x,y,z; i <= m; i++) {
        cin>>x>>y>>z;
        v.push_back({{x,y},z});
    }
    sort(v.begin(), v.end(), compare);
    ll ans = 0,mx = 0;
    for (auto i : v) {
        int x = i.first.first, y = i.first.second, w = i.second;
        if (f(x) != f(y)) {
            g(x, y);
            ans += w;
            mx=w;
        }
    }
    cout << ans-mx;
}