#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, k;
int d[2004][2004];
const int dir[] = {1, -1};
vector<pair<int, int>> v;
bool f() {
  for (auto i : v) {
    int x = i.first, y = i.second;
    bool flag1 = 0, flag2 = 0;
    for (int j = 0; j < 2; j++) {
      int xx = x + dir[j], yy = y + dir[j];
      if ((yy >= 1 && yy <= m) && d[x][yy] == 1) flag1 = 1;
      if ((xx >= 1 && xx <= n) && d[xx][y] == 1) flag2 = 1;
    }
    if (flag1 && flag2) {
      cout << x << " " << y << "\n";
      return 1;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> d[i][j];
      if (d[i][j] == 1) v.push_back({i, j});
    }
  }
  int ans = v.size();
  if (2 * k == ans) {
    cout << 0;
    return 0;
  }
  cout << 2 * k - ans << "\n";
  if (k == 1) {
    for (auto i : v) {
      cout << i.first << " " << i.second << "\n";
    }
    return 0;
  }
  if (2 * k - ans == 1) {
    if (f())
      return 0;
  }
  int x1 = inf, y1 = inf, x2 = 0, y2 = 0;
  for (auto i : v) {
    int x = i.first, y = i.second;
    x1 = min(x, x1);
    y1 = min(y, y1);
    x2 = max(x, x2);
    y2 = max(y, y2);
  }
  if (x1 == x2) {
    for (int i = 0; i < 2 * k - ans; i++) {
      cout << x1 << " " << y1 + ans - k + i << "\n";
    }
  } else if (y1 == y2) {
    for (int i = 0; i < 2 * k - ans; i++) {
      cout << x1 + ans - k + i << " " << y1 << "\n";
    }
  }
}