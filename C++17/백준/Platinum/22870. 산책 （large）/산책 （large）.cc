#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<vector<pair<ll, ll>>> v;
vector<ll> v1, v2;
unordered_set<ll> check;
const ll inf = 1e18 + 4;
int n, m, a, b;
ll ans = 0;
void f(vector<ll>& d, int s) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({ 0, s });
    d[s] = 0;
    while (!q.empty()) {
        ll x = q.top().second, y = q.top().first;
        q.pop();
        if (d[x] < y) continue;
        for (auto i : v[x]) {
            ll xx = i.first, yy = i.second;
            if (check.find(xx) != check.end()) continue;
            if (d[xx] <= y + yy) continue;
            d[xx] = y + yy;
            q.push({ d[xx], xx });
        }
    }
}
void g(int a, int b) {
    int s = a, p = a;//s:현제 위치, p:이전 위치
    while (s != b) {
        ll mn = inf;
        for (auto i : v[s]) {
            ll x = i.first, y = i.second;
            if (p == x) continue;
            if (v1[s] + y + v2[x] == v1[b]) mn = min(mn, x);
        }
        p = s;
        s = mn;
        if (s != b) check.insert(s);
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    v1.resize(n + 4, inf);
    v2.resize(n + 4, inf);
    v.resize(n + 4);
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        v[x].push_back({ y, z });
        v[y].push_back({ x, z });
    }
    cin >> a >> b;
    f(v1, a);//정방향
    f(v2, b);//역방향
    ans += v1[b];
    g(a, b);
    fill(v2.begin(), v2.end(), inf);
    f(v2, b);
    ans += v2[a];
    cout << ans;
}