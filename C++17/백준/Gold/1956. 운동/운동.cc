#include <iostream>
using namespace std;
int n, m;
int d[404][404];
const int inf = 1e9 + 4;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  fill(&d[0][0], &d[0][0] + 404 * 404, inf);
  for (int i = 1; i <= n; i++) {
    d[i][i] = 0;
  }
  for (int i = 1, x, y, z; i <= m; i++) {
    cin >> x >> y >> z;
    d[x][y] = z;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int mn = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j && d[i][j] != inf && d[j][i] != inf) {
        mn = min(mn, d[i][j] + d[j][i]);
      }
    }
  }
  cout << (mn == inf ? -1 : mn) << "\n";
}