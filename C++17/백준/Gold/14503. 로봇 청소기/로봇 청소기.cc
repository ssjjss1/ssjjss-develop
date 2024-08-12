#include <iostream>
using namespace std;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, r, c, d;
int a[54][54];
bool visited[54][54];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m >> r >> c >> d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  while (true) {
    if (!visited[r][c] && a[r][c] == 0) {
      visited[r][c] = 1;
      ans += 1;
    }
    bool flag = 0;
    for (int i = 0; i < 4; i++) {
      d = (d + 3) % 4;
      int xx = r + dx[d], yy = c + dy[d];
      if (a[xx][yy] == 0 && !visited[xx][yy]) {
        r = xx;
        c = yy;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      int dir = (d + 2) % 4;
      int xx = r + dx[dir], yy = c + dy[dir];
      if (a[xx][yy] == 1) break;
      else {
        r = xx, c = yy;
      }
    }
  }
  cout << ans;
}