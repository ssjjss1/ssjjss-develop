#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m;
int visited[24][24][24][24];
vector<pair<int, int>> v;
char c[24][24];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'o')
        v.push_back({i, j});
    }
  }
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({{v[0].first, v[0].second}, {v[1].first, v[1].second}});
  visited[v[0].first][v[0].second][v[1].first][v[1].second] = 1;
  int cnt = 0;
  while (!q.empty()) {
    int size = q.size();
    if (cnt >= 10) break;
    while (size--) {
      int x1 = q.front().first.first, y1 = q.front().first.second;
      int x2 = q.front().second.first, y2 = q.front().second.second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int xx1 = x1 + dx[i], yy1 = y1 + dy[i];
        int xx2 = x2 + dx[i], yy2 = y2 + dy[i];
        bool flag1 = (xx1 < 1 || xx1 > n || yy1 < 1 || yy1 > m);
        bool flag2 = (xx2 < 1 || xx2 > n || yy2 < 1 || yy2 > m);
        if (flag1 && flag2) continue;
        if (flag1 || flag2) {
          cout << cnt + 1;
          return 0;
        }
        if (c[xx1][yy1] == '#') {
          xx1 = x1;
          yy1 = y1;
        }
        if (c[xx2][yy2] == '#') {
          xx2 = x2;
          yy2 = y2;
        }
        if (!visited[xx1][yy1][xx2][yy2]) {
          visited[xx1][yy1][xx2][yy2] = 1;
          q.push({{xx1, yy1}, {xx2, yy2}});
        }
      }
    }
    cnt++;
  }
  cout << -1;
}