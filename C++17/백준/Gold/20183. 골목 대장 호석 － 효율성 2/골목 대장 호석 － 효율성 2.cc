#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18 + 4;
ll n, m, A, B, C;
vector<pair<ll, ll>> v[500004];
ll visited[100004];
struct P {
  ll a, b, c;
  bool operator>(const P &other) const { return a > other.a; }
};
ll f(ll mn) {
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, A, C});
  fill(visited, visited + n + 1, inf);
  visited[A] = 0;
  while (!q.empty()) {
    ll x = q.top().a, y = q.top().b, cnt = q.top().c;
    q.pop();
    if (y == B)
      return x;
    for (auto i : v[y]) {
      ll xx = i.first, yy = i.second, mon = cnt - yy;
      ll p = max(x, yy);
      if (p > mn || mon < 0) continue;
      if (visited[xx] > p) {
        visited[xx] = p;
        q.push({p, xx, mon});
      }
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m >> A >> B >> C;
  vector<ll> v1;
  for (int i = 1,x,y,z; i <= m; i++) {
    cin >> x >> y >> z;
    v[x].push_back({y, z});
    v[y].push_back({x, z});
    v1.push_back(z);
  }
  sort(v1.begin(), v1.end());
  v1.erase(unique(v1.begin(), v1.end()), v1.end());
  ll ans = inf;
  ll left = 0, right = v1.size() - 1;
  while (left <= right) {
    ll mid = (left + right) / 2;
    ll cnt = f(v1[mid]);
    if (cnt != -1) {
      ans = min(ans, cnt);
      right = mid - 1;
    } 
    else left = mid + 1;
  }
  cout << (ans == inf ? -1 : ans);
}