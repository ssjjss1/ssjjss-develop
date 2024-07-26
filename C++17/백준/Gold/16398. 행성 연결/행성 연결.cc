#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[1004];
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
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1,x; j <= n; j++) {
            cin >> x;
            v.push_back({ {i,j},x });
        }
    }
    sort(v.begin(), v.end(), compare);
    ll ans = 0;
    for (auto i : v) {
        int x = i.first.first, y = i.first.second, w = i.second;
        if (f(x) != f(y)) {
            g(x, y);
            ans += w;
        }
    }
    cout << ans;
}