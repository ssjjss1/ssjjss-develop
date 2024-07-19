#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;
const ll inf = 1e18;
int n, m, k;
ll visited[100004];
vector<pair<ll, ll>> v[500004];
vector<ll> v1;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1, x, y, z; i <= m; i++) {
    cin >> x >> y >> z;
    v[y].push_back({x, z});
  }
  fill(visited, visited + 100004, inf);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,greater<pair<ll, ll>>> q;
  for (int i = 1, x; i <= k; i++) {
    cin >> x;
    visited[x] = 0;
    q.push({0, x});
  }
  while (!q.empty()) {
    ll x = q.top().second, y = q.top().first;
    q.pop();
    if (visited[x] < y)
      continue;
    for (auto j : v[x]) {
      if (visited[j.first] > y + j.second) {
        visited[j.first] = y + j.second;
        q.push({y + j.second, j.first});
      }
    }
  }
  ll ans = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] > mx && visited[i] != inf)
      ans = i, mx = max(mx, visited[i]);
  }
  cout << ans << "\n" << mx;
}