#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 1e8 + 4;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int t, n, m;
void f(vector<vector<int>> &d, int x, int y, vector<vector<char>> &c) {
  queue<pair<int, int>> q;
  q.push({x, y});
  d[x][y] = 0;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || yy < 0 || xx > n + 1 || yy > m + 1 || c[xx][yy] == '*') continue;
      int ct = d[x][y] + (c[xx][yy] == '#');
      if (ct < d[xx][yy]) {
        d[xx][yy] = ct;
        q.push({xx,yy});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<char>> c(n + 4, vector<char>(m + 4));
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> c[i][j];
        if (c[i][j] == '$') v.push_back({i, j});
      }
    }
    vector<vector<int>> d1(n + 4, vector<int>(m + 4, inf));
    vector<vector<int>> d2(n + 4, vector<int>(m + 4, inf));
    vector<vector<int>> out(n + 4, vector<int>(m + 4, inf));
    f(d1, v[0].first, v[0].second, c);
    f(d2, v[1].first, v[1].second, c);
    f(out, 0, 0, c);
    long long mn = inf;
    for (int i = 0; i <= n+1; i++) {
      for (int j = 0; j <= m+1; j++) {
        if (c[i][j] == '*') continue;
        long long tc = d1[i][j] + d2[i][j] + out[i][j];
        if (c[i][j] == '#') tc -= 2;
        mn = min(mn, tc);
      }
    }
    cout << mn << "\n";
  }
}