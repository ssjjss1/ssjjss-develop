#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int inf=-1e9+4;
vector<int> v;
vector<vector<ll>> dp;
int t, n, m;
ll f(int x, int y) { // x: 현재까지 남은 점수, y: 현재까지 누적된 횟수
  if (x == 0) return 0;
  if (dp[x][y] != inf) return dp[x][y]; 
  for (int i = 0; i < m; i++) {
    if (x - y * v[i] >= 0) {
      dp[x][y] = max(dp[x][y], f(x - y * v[i], y + 1) + v[i]);
    }
  }
  return dp[x][y];
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    v.resize(m + 4);
    dp.assign(n + 4, vector<ll>(n + 4, inf));
    for (int i = 0; i < m; i++) cin >> v[i];
    ll ans = f(n, 1);
    if (ans > 0) cout << ans << "\n";
    else cout << -1 << "\n";
  }
}